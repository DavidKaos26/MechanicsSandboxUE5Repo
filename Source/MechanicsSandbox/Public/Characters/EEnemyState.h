#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum EEnemyState
{
	Idle UMETA(DisplayName = "Idle"),
	Approach UMETA(DisplayName = "Approach")
};