#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HealthBar.generated.h"

UINTERFACE(MinimalAPI, Blueprintable)
class UHealthBar : public UInterface
{
	GENERATED_BODY()
};


class MECHANICSSANDBOX_API IHealthBar
{
	GENERATED_BODY()

public:
	void UpdateHealthProgressBar(float NewPercentage);
};
