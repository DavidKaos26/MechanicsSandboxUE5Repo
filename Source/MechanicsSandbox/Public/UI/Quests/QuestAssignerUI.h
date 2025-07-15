#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "Quests/Data/QuestData.h"
#include "QuestAssignerUI.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UQuestAssignerUI : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* QuestName_Text;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* QuestDescription_Text;

	UPROPERTY(meta = (BindWidget))
    class UButton* AcceptQuest_Button;

	UPROPERTY(meta = (BindWidget))
    class UButton* Cancel_Button;

public:
    virtual void NativeConstruct() override;

	void SetQuestAssignerInfo(UQuestData* QuestData);

	UFUNCTION()
	void OnCancelButtonPressed();
	
};
