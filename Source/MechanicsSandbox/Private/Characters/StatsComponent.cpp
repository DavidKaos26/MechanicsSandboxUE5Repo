#include "Characters/StatsComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Net/UnrealNetwork.h"

UStatsComponent::UStatsComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UStatsComponent::BeginPlay()
{
	Super::BeginPlay();

	SetIsReplicatedByDefault(true);

	// Server initializes replicated values
    if (GetOwner()->HasAuthority())
    {
        HealthRep = Stats[EStat::Health];
		FTimerHandle TimerHandle;

		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UStatsComponent::InitializeHealthUpdate, 0.3f, false);

    }
}

void UStatsComponent::InitializeHealthUpdate()
{
	OnHealthUpdatedDelegate.Broadcast(); //Run on server
}

void UStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UStatsComponent, HealthRep);
}

void UStatsComponent::OnRep_HealthRep()
{
	Stats[EStat::Health] = HealthRep;

	OnHealthUpdatedDelegate.Broadcast(); //Run on clients
}

void UStatsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UStatsComponent::ReduceHealth(float Amount, AActor* Opponent)
{
	if(HealthRep <= 0.0f) { return; }

	HealthRep -= Amount;

	UKismetMathLibrary::Clamp(
		HealthRep, 
		0.0f, 
		Stats[EStat::MaxHealth]
	);

	if (GetOwner()->HasAuthority())
	{
		//Run on server, this delegate is also called on OnRep_HealthRep() once variable is replicated so that it applies to clients as well
		OnHealthUpdatedDelegate.Broadcast(); 
	}

	if (HealthRep <= 0.0f)
	{
		GEngine->AddOnScreenDebugMessage(3, 6.0f, FColor::Orange, TEXT("Health has reached less than 0 now!"));
		OnHealthReachesZeroDelegate.Broadcast();
	}
}

float UStatsComponent::GetHealthPercentageDecimal()
{
	return HealthRep / Stats[EStat::MaxHealth];
}

float UStatsComponent::GetHealth()
{
	return HealthRep;
}

