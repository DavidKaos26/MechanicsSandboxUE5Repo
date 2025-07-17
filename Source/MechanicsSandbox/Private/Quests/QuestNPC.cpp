#include "Quests/QuestNPC.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "Player/MainPlayerController.h"
#include "Quests/Data/QuestData.h"


AQuestNPC::AQuestNPC()
{
	PrimaryActorTick.bCanEverTick = true;

	InteractionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionSphere"));
    InteractionSphere->SetupAttachment(RootComponent);

}

void AQuestNPC::BeginPlay()
{
	Super::BeginPlay();

	if (InteractionSphere)
    {
        InteractionSphere->OnComponentBeginOverlap.AddDynamic(
            this,
            &AQuestNPC::OnInteractionSphereBeginOverlap
        );
    }
	
}

void AQuestNPC::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AQuestNPC::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AQuestNPC::OnInteractionSphereBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (OtherActor == this) { return; }

    APawn* Pawn = Cast<APawn>(OtherActor);

    if (Pawn)
    {
        AMainPlayerController* MainPlayerController = Cast<AMainPlayerController>(Pawn->GetController());
        if (MainPlayerController && QuestDataToAssign && MainPlayerController->IsLocalController())
        {
            MainPlayerController->ShowQuestAssignerUI();
            MainPlayerController->SetQuestAssignerUIInfo(QuestDataToAssign);
        }
    }
}
