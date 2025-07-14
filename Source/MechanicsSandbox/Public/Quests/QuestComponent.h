#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/QuestData.h"
#include "QuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UQuestData* CurrentQuest;

protected:
	virtual void BeginPlay() override;

public:	
	UQuestComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	UQuestData* GetCurrentQuest();

	UFUNCTION(BlueprintCallable)
	void SetCurrentQuest(UQuestData* NewQuest);
		
};
