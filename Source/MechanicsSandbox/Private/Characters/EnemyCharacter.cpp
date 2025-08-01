#include "Characters/EnemyCharacter.h"
#include "Combat/CombatComponent.h"
#include "Characters/StatsComponent.h"
#include "Combat/TraceComponent.h"
#include "Characters/EEnemyState.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "Components/WidgetComponent.h"
#include "Player/PlayerCharacter.h"


AEnemyCharacter::AEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	StatComp = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("Combat Component"));
	TraceComp = CreateDefaultSubobject<UTraceComponent>(TEXT("TraceComponent"));
	HealthBarOverHeadWidget = CreateDefaultSubobject<UWidgetComponent>("HealthBarOverHeadWidget");
	HealthBarOverHeadWidget->SetupAttachment(RootComponent);
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		ControllerRef = GetController<AAIController>();

		if (!ControllerRef) { return; }

		BlackboardComponent = ControllerRef->GetBlackboardComponent();

		if (!BlackboardComponent) { return; }
		
		BlackboardComponent->SetValueAsEnum(
			TEXT("CurrentState"), 
			InitialState
		);
	}
}

void AEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!PawnTarget) { return; }

	BlackboardComponent->SetValueAsVector(
		TEXT("CurrentTargetLocation"),
		PawnTarget->GetActorLocation()
	);
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

void AEnemyCharacter::DetectPawn(APawn* PawnDetected)
{	
	if (!BlackboardComponent) { return; }

	EEnemyState CurrentState {
		static_cast<EEnemyState>(BlackboardComponent->GetValueAsEnum(TEXT("CurrentState")))
	};

	APlayerCharacter* DetectedCharacter = Cast<APlayerCharacter>(PawnDetected);

	if(!DetectedCharacter || CurrentState != EEnemyState::Idle) { return; }

	PawnTarget = PawnDetected;

	BlackboardComponent->SetValueAsEnum(
		TEXT("CurrentState"), 
		EEnemyState::Approach
	);	
}