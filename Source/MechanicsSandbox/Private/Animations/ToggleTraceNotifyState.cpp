#include "Animations/ToggleTraceNotifyState.h"
#include "Combat/TraceComponent.h"


void UToggleTraceNotifyState::NotifyBegin(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
    if (!MeshComp) { return; }

    AActor* Owner = MeshComp->GetOwner();
    if (!Owner) { return; }

    UTraceComponent* TraceComponent { 
        MeshComp->GetOwner()->FindComponentByClass<UTraceComponent>() };

    if (!IsValid(TraceComponent)) { return; }

    TraceComponent->bIsAttacking = true;
}

void UToggleTraceNotifyState::NotifyEnd(USkeletalMeshComponent * MeshComp, UAnimSequenceBase * Animation, const FAnimNotifyEventReference& EventReference)
{
    if (!MeshComp) { return; }

    AActor* Owner = MeshComp->GetOwner();
    if (!Owner) { return; }
    
    UTraceComponent* TraceComponent { 
        MeshComp->GetOwner()->FindComponentByClass<UTraceComponent>() };

    if (!IsValid(TraceComponent)) { return; }

    TraceComponent->bIsAttacking = false;
}

