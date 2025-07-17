#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "WeaponActor.generated.h"

UCLASS()
class MECHANICSSANDBOX_API AWeaponActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponActor();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* StartWeaponDamageLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* EndWeaponDamageLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WeaponDamage { 10.0f };

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
