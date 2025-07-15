#include "Player/MainPlayerController.h"
#include "UI/Quests/QuestAssignerUI.h"
#include "Quests/Data/QuestData.h"
#include "GameFramework/Pawn.h"


void AMainPlayerController::ShowQuestAssignerUI() 
{
    QuestAssignerUIWidget = CreateWidget<UQuestAssignerUI>(this, QuestAssignerUIWidgetClass);
    if (QuestAssignerUIWidget)
    {
        QuestAssignerUIWidget->AddToViewport();
        bShowMouseCursor = true;
        FInputModeGameOnly GameInputMode;
        SetInputMode(GameInputMode);

        APawn* PlayerPawn = GetPawn();
        if (PlayerPawn)
        {
            PlayerPawn->DisableInput(this);
        }
    }
}

void AMainPlayerController::SetQuestAssignerUIInfo(UQuestData* QuestData)
{
    if (!QuestData) { return; }

    if (QuestAssignerUIWidget)
    {
        QuestAssignerUIWidget->SetQuestAssignerInfo(QuestData);
    }
}
