
#pragma once

#include "CoreMinimal.h"
#include "FMyStruct.generated.h"

USTRUCT()
struct GIZMOPROJECT_API FMyStruct
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	int test = 5;
};
