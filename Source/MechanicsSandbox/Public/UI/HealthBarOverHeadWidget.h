#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "Interfaces/HealthBar.h"
#include "HealthBarOverHeadWidget.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UHealthBarOverHeadWidget : public UUserWidget, public IHealthBar
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget), Replicated)
	class UTextBlock* HealthText;

	UPROPERTY(meta = (BindWidget), Replicated)
	UProgressBar* HealthProgressBar;
	
protected:
/* 	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
 */
public:
	UFUNCTION(BlueprintCallable)
	virtual void UpdateHealthProgressBar(float NewPercentage);

	UFUNCTION(BlueprintCallable)
	void UpdateHealthText(float NewValue);

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
