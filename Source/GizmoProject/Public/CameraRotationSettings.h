// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCameraOffset.h"
#include "Engine/DataAsset.h"
#include "CameraRotationSettings.generated.h"

/**
 * 
 */
UCLASS()
class GIZMOPROJECT_API UCameraRotationSettings : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = Offset)
	FCameraOffset offset;
	UPROPERTY(EditAnywhere, Category = Settings, meta = (UIMin = 0, UIMax = 500, ClampMin = 0, ClampMax = 500))
	float rotationSpeed = 10;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useLookAt = true;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useSmoothLookAt = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos rotation settings")
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos rotation settings")
		FColor validRotationToColor = FColor::Green;

public:
	FORCEINLINE float RotationSpeed() const { return rotationSpeed; }
	FORCEINLINE bool UseLookAt() const { return useLookAt; }
	FORCEINLINE bool UseSmoothLookAt() const { return useSmoothLookAt; }
	FORCEINLINE bool DrawGizmos() const { return drawGizmos; }

	void DrawLookAtStatus(const UWorld* _world, const FVector& _origin);
	void DrawLookAtTarget(const UWorld* _world, FVector _targetPosition, FVector _origin, FColor _color);
	FVector GetLookAtTarget(const AActor* _target) const;

};
