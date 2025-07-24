#include "Characters/EnemyCharacter.h"
#include "Combat/CombatComponent.h"
#include "Characters/StatsComponent.h"
#include "Combat/TraceComponent.h"
#include "Characters/EEnemyState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"


AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	StatComp = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("Combat Component"));
	TraceComp = CreateDefaultSubobject<UTraceComponent>(TEXT("TraceComponent"));
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle MyTimerHandle;

	GetWorld()->GetTimerManager().SetTimer(
		MyTimerHandle,          
        this,                   
        &AEnemyCharacter::Attack,  
        2.0f,                   
        true                    
	);

	ControllerRef = GetController<AAIController>();

	BlackboardComponent = ControllerRef->GetBlackboardComponent();
	
	BlackboardComponent->SetValueAsEnum(
		TEXT("CurrentState"), 
		InitialState
	);
	
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEnemyCharacter::Attack()
{
	if (CombatComp)
	{
		CombatComp->ComboAttack();
	}
}

void AEnemyCharacter::DetectPawn(APawn* PawnDetected, APawn* PawnToDetect)
{	
	EEnemyState CurrentState {
		static_cast<EEnemyState>(BlackboardComponent->GetValueAsEnum(TEXT("CurrentState")))
	};

	if(PawnDetected != PawnToDetect || CurrentState != EEnemyState::Idle) { return; }

	UE_LOG(LogTemp ,Warning, TEXT("Detect Pawn function called!!"));

	BlackboardComponent->SetValueAsEnum(
		TEXT("CurrentState"), 
		EEnemyState::Approach
	);	
}


