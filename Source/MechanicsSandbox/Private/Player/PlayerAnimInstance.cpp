#include "Player/PlayerAnimInstance.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "KismetAnimationLibrary.h"
#include "Player/PlayerCharacter.h"


void UPlayerAnimInstance::NativeBeginPlay()
{
    Super::NativeBeginPlay();

    APawn* PawnRef { TryGetPawnOwner() };

    if (!IsValid(PawnRef)) { return; }

    PlayerCharacterRef = Cast<APlayerCharacter>(PawnRef);
}

void UPlayerAnimInstance::UpdateVelocity()
{
    APawn* PawnRef { TryGetPawnOwner() };

    if(!IsValid(PawnRef)) { return; }

    FVector Velocity { PawnRef->GetVelocity() };

    CurrentVelocity = static_cast<float>(Velocity.Length());
}

void UPlayerAnimInstance::UpdateDirection()
{
    APawn* PawnRef { TryGetPawnOwner() };

    if (!IsValid(PawnRef)) { return; }

    FVector Velocity { PawnRef->GetVelocity() };
    FRotator Rotation { PawnRef->GetActorRotation() };

    float Direction = UKismetAnimationLibrary::CalculateDirection(Velocity, Rotation);

    CurrentDirection = Direction;
}   

void UPlayerAnimInstance::UpdateIsJumping()
{
    ACharacter* Character = Cast<ACharacter>(TryGetPawnOwner());
    if (!IsValid(Character)) { return; }

    bIsFalling = Character->GetCharacterMovement()->IsFalling();
}


