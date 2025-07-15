#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SphereComponent.h"
#include "Quests/Data/QuestData.h"
#include "QuestNPC.generated.h"

UCLASS()
class MECHANICSSANDBOX_API AQuestNPC : public ACharacter
{
	GENERATED_BODY()

public:
	AQuestNPC();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    USphereComponent* InteractionSphere;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    UQuestData* QuestDataToAssign;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
    void OnInteractionSphereBeginOverlap(
        UPrimitiveComponent* OverlappedComp,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );


};
