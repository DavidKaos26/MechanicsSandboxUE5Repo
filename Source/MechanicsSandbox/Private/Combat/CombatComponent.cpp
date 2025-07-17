#include "Combat/CombatComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Combat/WeaponActor.h"
#include "GameFramework/Character.h"
#include "Components/PrimitiveComponent.h"
#include "Net/UnrealNetwork.h"


UCombatComponent::UCombatComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UCombatComponent::BeginPlay()
{
	Super::BeginPlay();

	SetIsReplicatedByDefault(true);

	if(WeaponClass)
	{
		CurrentWeapon = GetWorld()->SpawnActor<AWeaponActor>(WeaponClass);

		CharacterRef = Cast<ACharacter>(GetOwner());

		if(CharacterRef)
		{
			CurrentWeapon->AttachToComponent(CharacterRef->GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("Weapon_Socket"));
			CurrentWeapon->SetOwner(CharacterRef);
			OnWeaponAssignedDelegate.Broadcast(CurrentWeapon);
		}
	}
}

void UCombatComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UCombatComponent, AttackMontages);
}



void UCombatComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UCombatComponent::ComboAttack()
{
	if (!bCanAttack) return;

	bCanAttack = false;

	ComboCounter++;

	if (ComboCounter >= AttackMontages.Num())
	{
		ComboCounter = 0;
	}

	if (CharacterRef)
	{
		if (CharacterRef->IsLocallyControlled())
		{
			ServerPlayMontage(AttackMontages[ComboCounter], AnimationsPlayRate);
		}
	}
}

void UCombatComponent::HandleResetAttack()
{
	bCanAttack = true;
}

void UCombatComponent::ServerPlayMontage_Implementation(UAnimMontage* MontageToPlay, float PlayRate)
{
    MulticastPlayMontage(MontageToPlay, PlayRate);
}

void UCombatComponent::MulticastPlayMontage_Implementation(UAnimMontage* MontageToPlay, float PlayRate)
{
    if (CharacterRef)
    {
		CharacterRef->PlayAnimMontage(AttackMontages[ComboCounter], AnimationsPlayRate);
    }
}



