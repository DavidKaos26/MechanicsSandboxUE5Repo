#include "Combat/TraceComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/DamageEvents.h"


UTraceComponent::UTraceComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UTraceComponent::BeginPlay()
{
	Super::BeginPlay();	
}


void UTraceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (!bIsAttacking) { return; }

	if (!CurrentWeapon) { return; }	

	StartTraceLocation = CurrentWeapon->StartWeaponDamageLocation->GetComponentLocation();
	EndTraceLocation = CurrentWeapon->EndWeaponDamageLocation->GetComponentLocation();

	TArray<FHitResult> OutResults;
	FRotator Rotation = FRotator::ZeroRotator;
	FQuat QuatRotation = Rotation.Quaternion();

	double WeaponDistance{
		FVector::Distance(StartTraceLocation, EndTraceLocation)
	};

	FVector BoxHalfExtent{ 
		BoxCollisionLength, BoxCollisionLength, WeaponDistance
	};

	BoxHalfExtent /= 2;

	FCollisionShape Box{ 
		FCollisionShape::MakeBox(BoxHalfExtent)
	};

	FCollisionQueryParams IgnoreParams{
		FName { TEXT("Ignore Params") },
		false,
		GetOwner()
	};

	bool bHasFoundTargets { GetWorld()->SweepMultiByChannel(
			OutResults,
			StartTraceLocation,
			EndTraceLocation,
			QuatRotation,
			ECollisionChannel::ECC_GameTraceChannel1,
			Box, IgnoreParams
		)
	};

	if (bDebugMode)
	{
		FVector CenterPoint { UKismetMathLibrary::VLerp(
			StartTraceLocation, 
			EndTraceLocation, 
			0.5f
		) };

		UKismetSystemLibrary::DrawDebugBox(
			GetWorld(),
			CenterPoint,
			Box.GetExtent(),
			bHasFoundTargets ? FLinearColor::Green : FLinearColor::Red,
			QuatRotation.Rotator(),
			1.0f,
			2.0f
		);
	}

	if (OutResults.Num() == 0) { return; }

	if (CurrentWeapon)
	{
		FDamageEvent TargetAttackEvent;

		for (const FHitResult& Hit : OutResults)
		{
			AActor* TargetActor { Hit.GetActor() };
			if (TargetActor)
			{
				if (TargetsToIgnore.Contains(TargetActor)) { continue; }

				TargetActor->TakeDamage(
					CurrentWeapon->WeaponDamage,
					TargetAttackEvent,
					GetOwner()->GetInstigatorController(),
					GetOwner()
				);

				TargetsToIgnore.AddUnique(TargetActor);
			}
		}
	}

}

void UTraceComponent::HandleResetAttack()
{
	TargetsToIgnore.Empty();
}


