#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestData.generated.h"


UCLASS()
class MECHANICSSANDBOX_API UQuestData : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QuestName; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString QuestDescription;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int TargetValue;
	
};
