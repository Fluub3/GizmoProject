// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FCameraOffset.h"
#include "Engine/DataAsset.h"
#include "CameraPositionSettings.generated.h"

/**
 * 
 */
UCLASS()
class GIZMOPROJECT_API UCameraPositionSettings : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = Offset)
	FCameraOffset offset;
	UPROPERTY(EditAnywhere, Category = Settings, meta = (UIMin = 0, UIMax = 500, ClampMin = 0, ClampMax = 500))
	float positionSpeed = 10;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useMoveTo = true;
	UPROPERTY(EditAnywhere, Category = Settings)
		bool useSmoothMove = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos position settings")
		bool drawGizmos = true;
	UPROPERTY(EditAnywhere, Category = "Gizmos position settings")
		FColor validMoveToColor = FColor::Yellow;

public:
	FORCEINLINE float PositionSpeed() const { return positionSpeed; }
	FORCEINLINE bool UseMoveTo() const {  return useMoveTo; }
	FORCEINLINE bool UseSmoothMove() const { return useSmoothMove; }
	FORCEINLINE bool DrawGizmos() const { return drawGizmos; }
	

	FVector GetCameraPosition(const AActor* _target) const;
	void DrawCameraPosition(const UWorld* _world, const FTransform& _target);
	void DrawMoveToStatus(FVector _origin);
};
