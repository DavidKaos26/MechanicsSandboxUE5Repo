#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/WeaponActor.h"
#include "Animation/AnimMontage.h"
#include "GameFramework/Character.h"
#include "CombatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(
	FOnWeaponAssignedSignature,
	UCombatComponent, OnWeaponAssignedDelegate,
	AWeaponActor*, Weapon
);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UCombatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UCombatComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AWeaponActor> WeaponClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AWeaponActor* CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated)
	TArray<UAnimMontage*> AttackMontages;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AnimationsPlayRate = 1.5f;

	UPROPERTY(BlueprintAssignable)
	FOnWeaponAssignedSignature OnWeaponAssignedDelegate;

	int ComboCounter { 0 };

	ACharacter* CharacterRef;

	UPROPERTY(VisibleAnywhere)
	bool bCanAttack { true };

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ComboAttack();

	UFUNCTION(BlueprintCallable)
	void HandleResetAttack();

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION(Server, Reliable)
	void ServerPlayMontage(UAnimMontage* MontageToPlay, float PlayRate);

	UFUNCTION(NetMulticast, Reliable)
	void MulticastPlayMontage(UAnimMontage* MontageToPlay, float PlayRate);
		
};
