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
    if (GetOwnerRole() == ROLE_Authority)
    {
        HealthRep = Stats[EStat::Health];
    }
}

void UStatsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UStatsComponent, HealthRep);
}

void UStatsComponent::OnRep_HealthRep()
{
	Stats[EStat::Health] = HealthRep;
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
}

