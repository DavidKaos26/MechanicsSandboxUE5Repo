#include "Characters/AI/BTTask_Attack.h"
#include "GameFramework/Pawn.h"
#include "AIController.h"
#include "Characters/EnemyCharacter.h"


UBTTask_Attack::UBTTask_Attack()
{
    NodeName = TEXT("Attack");
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    AAIController* AIController = OwnerComp.GetAIOwner();
    if (!AIController) { return EBTNodeResult::Failed; }

    APawn* ControlledPawn = AIController->GetPawn();
    if (!ControlledPawn) { return EBTNodeResult::Failed; }

    AEnemyCharacter* EnemyCharacter = Cast<AEnemyCharacter>(ControlledPawn);
    if (!EnemyCharacter) { return EBTNodeResult::Failed; }

    EnemyCharacter->Attack();

    return EBTNodeResult::Succeeded;
}
