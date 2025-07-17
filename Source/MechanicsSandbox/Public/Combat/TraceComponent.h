#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/WeaponActor.h"
#include "TraceComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UTraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UTraceComponent();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector StartTraceLocation;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	FVector EndTraceLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	double BoxCollisionLength { 30.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bDebugMode { false };

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	AWeaponActor* CurrentWeapon;

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
