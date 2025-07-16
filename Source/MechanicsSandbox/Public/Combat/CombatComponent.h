#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/WeaponActor.h"
#include "Animation/AnimMontage.h"
#include "CombatComponent.generated.h"


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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UAnimMontage*> AttackMontages;

	int ComboCounter { 0 };

	class APlayerCharacter* CharacterRef;

	UPROPERTY(VisibleAnywhere)
	bool bCanAttack { true };

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ComboAttack();

		
};
