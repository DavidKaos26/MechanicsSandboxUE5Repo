#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Quests/QuestComponent.h"
#include "Combat/CombatComponent.h"
#include "Combat/TraceComponent.h"
#include "Characters/StatsComponent.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class MECHANICSSANDBOX_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class USpringArmComponent* CameraBoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* FollowCamera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UQuestComponent* QuestComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UCombatComponent* CombatComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UTraceComponent* TraceComponent; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UStatsComponent* StatComponent; 

	float StartingSpeed { 0.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SprintSpeed { 700.0f };

protected:
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void Turn(float Value);
	void LookUp(float Value);
	void Attack();
	void Sprint();
	void StopSprint();

	UFUNCTION(Server, Reliable)
	void Server_StartSprinting();

	UFUNCTION(Server, Reliable)
	void Server_StopSprinting();

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
