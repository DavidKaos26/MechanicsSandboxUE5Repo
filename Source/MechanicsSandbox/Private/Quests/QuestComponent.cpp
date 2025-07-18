#include "Quests/QuestComponent.h"

UQuestComponent::UQuestComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UQuestComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UQuestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UQuestComponent::SetCurrentQuest(UQuestData* NewQuest)
{
	CurrentQuest = NewQuest;
}

UQuestData* UQuestComponent::GetCurrentQuest()
{
	return CurrentQuest;
}


