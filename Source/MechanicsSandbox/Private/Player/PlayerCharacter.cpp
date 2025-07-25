#include "Player/PlayerCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Quests/QuestComponent.h"
#include "Combat/CombatComponent.h"
#include "Combat/TraceComponent.h"
#include "Characters/StatsComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("Camera Boom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.0f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Follow Camera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	//Actor Components
	QuestComp = CreateDefaultSubobject<UQuestComponent>(TEXT("Quest Component"));
	CombatComp = CreateDefaultSubobject<UCombatComponent>(TEXT("Combat Component"));
 	TraceComponent = CreateDefaultSubobject<UTraceComponent>(TEXT("Trace Component"));
	StatComponent = CreateDefaultSubobject<UStatsComponent>(TEXT("Stats Component"));
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();

	StartingSpeed = GetCharacterMovement()->MaxWalkSpeed;

}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Attack", IE_Pressed, this, &APlayerCharacter::Attack);
	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &APlayerCharacter::StopSprint);

	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::LookUp);

}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void APlayerCharacter::MoveForward(float Value)
{
	if (Controller != nullptr && Value != 0.0f)
	{
		const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X));
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::MoveRight(float Value)
{
	if (Controller != nullptr && Value != 0.0f)
	{
		const FRotator YawRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);
		const FVector Direction(FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y));
		AddMovementInput(Direction, Value);
	}
}

void APlayerCharacter::Turn(float Value)
{
	AddControllerYawInput(Value);
}

void APlayerCharacter::LookUp(float Value)
{
	AddControllerPitchInput(Value);
}

void APlayerCharacter::Attack()
{
	if (CombatComp)
	{
		CombatComp->ComboAttack();
	}
}

void APlayerCharacter::Sprint()
{
	//GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;

	if (HasAuthority())
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintSpeed;
	}
	else
	{
		Server_StartSprinting();
	}
}

void APlayerCharacter::StopSprint()
{
	//GetCharacterMovement()->MaxWalkSpeed = StartingSpeed;

	if (HasAuthority())
	{
		GetCharacterMovement()->MaxWalkSpeed = StartingSpeed;
	}
	else
	{
		Server_StopSprinting();
	}
}

void APlayerCharacter::Server_StartSprinting_Implementation()
{
    GetCharacterMovement()->MaxWalkSpeed = SprintSpeed; // Example: 600.f
}

void APlayerCharacter::Server_StopSprinting_Implementation()
{
    GetCharacterMovement()->MaxWalkSpeed = StartingSpeed; // Example: 300.f
}





