#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/Quests/QuestAssignerUI.h"
#include "Quests/Data/QuestData.h"
#include "MainPlayerController.generated.h"


UCLASS()
class MECHANICSSANDBOX_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> QuestAssignerUIWidgetClass;

	UQuestAssignerUI* QuestAssignerUIWidget;

public:
	void ShowQuestAssignerUI();

	void SetQuestAssignerUIInfo(UQuestData* QuestData);
};
