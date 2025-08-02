#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/ProgressBar.h"
#include "HealthBarOverHeadWidget.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UHealthBarOverHeadWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Replicated)
	class UTextBlock* HealthText;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget), Replicated)
	UProgressBar* HealthProgressBar;
	
protected:
/* 	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
 */
public:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

};
