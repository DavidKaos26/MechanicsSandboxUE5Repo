#include "Characters/AI/BTTask_ApproachAttack.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AIController.h"

/* UBTTask_ApproachAttack::UBTTask_ApproachAttack()
{
    NodeName = "Approach Attack";
    bNotifyTick = true; 
}

EBTNodeResult::Type UBTTask_ApproachAttack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    Super::ExecuteTask(OwnerComp, NodeMemory);

    BlackboardComp = OwnerComp.GetBlackboardComponent();
    AIControllerRef = OwnerComp.GetAIOwner();

    if (!BlackboardComp || !AIControllerRef)
    {
        return EBTNodeResult::Failed;
    }

    GEngine->AddOnScreenDebugMessage(12, 5.0f, FColor::Green, TEXT("BlackboardComp value now set!"));

    return EBTNodeResult::InProgress;
}

void UBTTask_ApproachAttack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    if (!BlackboardComp) { return; }
    CurrentTarget = BlackboardComp->GetValueAsObject(TEXT("CurrentTarget"));

    ApproachTarget();

    GEngine->AddOnScreenDebugMessage(6, 0.5f, FColor::Green, TEXT("Target location key is valid should start moving to it nowwww!"));
    UE_LOG(LogTemp, Warning, TEXT("Target location key is valid should start moving to it nowwww"));
}

void UBTTask_ApproachAttack::ApproachTarget()
{
    FAIMoveRequest MoveRequest { TargetLocation };

    if (!AIControllerRef) { return; }

    MoveRequest.SetUsePathfinding(true);
    MoveRequest.SetAcceptanceRadius(200.0f);

    AIControllerRef->MoveTo(MoveRequest);
    AIControllerRef->SetFocus(TargetLocation);

}
 */