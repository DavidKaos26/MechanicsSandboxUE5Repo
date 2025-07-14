#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "QuestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UQuestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UQuestComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
