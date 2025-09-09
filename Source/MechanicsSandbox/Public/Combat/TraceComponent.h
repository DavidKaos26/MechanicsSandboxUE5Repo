#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/WeaponActor.h"
#include "TraceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTraceComponent();

	FVector StartTraceLocation;
	FVector EndTraceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double BoxCollisionLength { 30.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDebugMode { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AWeaponActor* CurrentWeapon;

	TArray<AActor*> TargetsToIgnore;

	UPROPERTY(VisibleAnywhere)
	bool bIsAttacking { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AWeaponActor* CurrentWeaponActor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "No Weapon Actor")
	FName Start;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "No Weapon Actor")
	FName End;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "No Weapon Actor")
	FName Rotation;

	FQuat QuatRotation;

	USkeletalMeshComponent* SkeletalComp;


protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void HandleResetAttack();

	UFUNCTION(BlueprintCallable)
	void SetWeaponActor(AWeaponActor* WeaponActor);
		
};
