#include "Combat/WeaponActor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"


AWeaponActor::AWeaponActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComp = CreateDefaultSubobject<USceneComponent>(TEXT("Root Scene Component"));
	SetRootComponent(RootComp);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Weapon Mesh"));
	WeaponMesh->SetupAttachment(RootComp);

	StartWeaponDamageLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Start Weapon Damage Location"));
	StartWeaponDamageLocation->SetupAttachment(RootComp);

	EndWeaponDamageLocation = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("End Weapon Damage Location"));
	EndWeaponDamageLocation->SetupAttachment(RootComp);
}

void AWeaponActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWeaponActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

