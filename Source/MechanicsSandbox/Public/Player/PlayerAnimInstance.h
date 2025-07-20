#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Player/PlayerCharacter.h"
#include "PlayerAnimInstance.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UPlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	APlayerCharacter* PlayerCharacterRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentVelocity { 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CurrentDirection { 0.0f };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	bool bIsFalling { false };

protected:
	virtual void NativeBeginPlay();

public:
	UFUNCTION(BlueprintCallable)
	void UpdateVelocity();

	UFUNCTION(BlueprintCallable)
	void UpdateDirection();

	UFUNCTION(BlueprintCallable)
	void UpdateIsJumping();
};
