#include "UI/Quests/QuestAssignerUI.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "GameFramework/PlayerController.h"
#include "Quests/Data/QuestData.h"
#include "GameFramework/Pawn.h"


void UQuestAssignerUI::NativeConstruct()
{
    Super::NativeConstruct();

    if (Cancel_Button)
    {
        Cancel_Button->OnClicked.AddDynamic(this, &UQuestAssignerUI::OnCancelButtonPressed);
    }
}

void UQuestAssignerUI::SetQuestAssignerInfo(UQuestData* QuestData)
{
    if (!QuestData) { return; }

    if (QuestName_Text && !QuestData->QuestName.IsEmpty())
    {
        QuestName_Text->SetText(FText::FromString(QuestData->QuestName));
    }

    if (QuestDescription_Text && !QuestData->QuestDescription.IsEmpty())
    {
        QuestDescription_Text->SetText(FText::FromString(QuestData->QuestDescription));
    }
}

void UQuestAssignerUI::OnCancelButtonPressed()
{
    RemoveFromParent();

    APlayerController* PC = GetOwningPlayer();
    if (PC)
    {
        PC->bShowMouseCursor = false;
        FInputModeGameOnly InputMode;
        PC->SetInputMode(InputMode);

        APawn* PlayerPawn = PC->GetPawn();
        if (PlayerPawn)
        {
            PlayerPawn->EnableInput(PC);
        }
    }
}