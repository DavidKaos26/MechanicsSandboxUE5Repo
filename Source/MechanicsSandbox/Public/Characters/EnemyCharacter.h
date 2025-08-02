#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Combat/CombatComponent.h"
#include "Characters/StatsComponent.h"
#include "Combat/TraceComponent.h"
#include "Characters/EEnemyState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Components/WidgetComponent.h"
#include "Animation/AnimMontage.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class MECHANICSSANDBOX_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UStatsComponent* StatsComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UCombatComponent* CombatComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UTraceComponent* TraceComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Actor Components")
	UWidgetComponent* HealthBarOverHeadWidget;

	UPROPERTY(EditAnywhere)
	TEnumAsByte<EEnemyState> InitialState;

	AAIController* ControllerRef;

	UBlackboardComponent* BlackboardComponent;

	APawn* PawnTarget;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Replicated, Category = "Animations")
	UAnimMontage* DeathMontage;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	void Attack();

	UFUNCTION(BlueprintCallable)
	void DetectPawn(APawn* PawnDetected);

	UFUNCTION(BlueprintCallable)
	void HandleDeath();

};
