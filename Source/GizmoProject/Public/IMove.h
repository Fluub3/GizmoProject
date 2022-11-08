// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IMove.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIMove : public UInterface
{
	GENERATED_BODY()
};

class GIZMOPROJECT_API IIMove
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Movement)
		void MoveToTarget();
};
