#include "UI/HealthBarOverHeadWidget.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "Net/UnrealNetwork.h"



void UHealthBarOverHeadWidget::UpdateHealthProgressBar(float NewPercentage)
{
    if (!HealthProgressBar) { return; }

    HealthProgressBar->SetPercent(NewPercentage);
}

void UHealthBarOverHeadWidget::UpdateHealthText(float NewValue)
{
    if (!HealthText) { return; }

    int Value = static_cast<int>(NewValue);

    FText NewText = FText::AsNumber(Value);
    HealthText->SetText(NewText);
}

void UHealthBarOverHeadWidget::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
}


