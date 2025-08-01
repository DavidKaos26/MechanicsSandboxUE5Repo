#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Characters/EStat.h"
#include "StatsComponent.generated.h"


DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE(
	FOnHealthUpdatedSignature,
	UStatsComponent, OnHealthUpdatedDelegate	
);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MECHANICSSANDBOX_API UStatsComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStatsComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<TEnumAsByte<EStat>, float> Stats;

	// Replicated stat values
    UPROPERTY(ReplicatedUsing = OnRep_HealthRep)
    float HealthRep;

	UPROPERTY(BlueprintAssignable)
	FOnHealthUpdatedSignature OnHealthUpdatedDelegate;
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	UFUNCTION()
    void OnRep_HealthRep();

	UFUNCTION(BlueprintCallable)
	void ReduceHealth(float Amount, AActor* Opponent);

	UFUNCTION(BlueprintPure)
	float GetHealthPercentageDecimal();

	UFUNCTION(BlueprintPure)
	float GetHealth();

};
