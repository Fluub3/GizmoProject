// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FCameraOffset.generated.h"

/**
 * 
 */
USTRUCT()
struct GIZMOPROJECT_API FCameraOffset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float xOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float yOffset = 0;
	UPROPERTY(EditAnywhere, meta = (UIMin = -2000, ClampMin = -2000, UIMax = 2000, ClampMax = 2000))
		float zOffset = 0;
	UPROPERTY(EditAnywhere)
		bool useLocalOffset = true;

public:
	FORCEINLINE FVector Offset() const { return FVector(xOffset, yOffset, zOffset); }
	FORCEINLINE bool UseLocalOffset() { return useLocalOffset; }
	FORCEINLINE void SetLocalOffset(bool _enable) { useLocalOffset = _enable; }
	FORCEINLINE FVector GetLocalOffset(const AActor* _ref) const
	{
		if (!_ref)
			return Offset();
		FVector _offsetLocal = FVector::ZeroVector;
		_offsetLocal = _ref->GetActorLocation()
			+ _ref->GetActorForwardVector() * xOffset
			+ _ref->GetActorUpVector() * zOffset
			+ _ref->GetActorRightVector() * yOffset;
		return _offsetLocal;
	}

};
