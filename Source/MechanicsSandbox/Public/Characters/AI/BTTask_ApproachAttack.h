#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BTTask_ApproachAttack.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UBTTask_ApproachAttack : public UBTTaskNode
{
	GENERATED_BODY()

	AAIController* AIControllerRef;
	UBlackboardComponent* BlackboardComp;
	AActor* CurrentTarget;

public:
/* 	UBTTask_ApproachAttack();
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	void ApproachTarget(); */
	
};
