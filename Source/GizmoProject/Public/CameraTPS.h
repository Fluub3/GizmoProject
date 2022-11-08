// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CameraRotationSettings.h"
#include "CameraPositionSettings.h"
#include "Camera/CameraComponent.h"
#include "CameraTPS.generated.h"

UCLASS()
class GIZMOPROJECT_API ACameraTPS : public AActor
{
	GENERATED_BODY()
	UPROPERTY(VisibleAnywhere, Category = CameraTPS)
		TObjectPtr<UCameraComponent> cameraTarget = nullptr;

	UPROPERTY(EditAnywhere, Category = CameraTPS)
		TObjectPtr<UCameraRotationSettings> lookAtSettings = nullptr;

	UPROPERTY(EditAnywhere, Category = CameraTPS)
		TObjectPtr<UCameraPositionSettings> moveToSettings = nullptr;

	UPROPERTY(EditAnywhere, Category = CameraTPS)
		TObjectPtr<AActor> target = nullptr;
	
public:	
	FORCEINLINE FVector CurrentCameraLocation() const { return GetActorLocation(); }
	FORCEINLINE FVector CurrentTargetLocation() const 
	{
		return target ? lookAtSettings->GetLookAtTarget(target) : CurrentCameraLocation();
	}
	FORCEINLINE FRotator CurrentCameraRotation() const { return GetActorRotation(); }
	ACameraTPS();


private:
	void InitCamera();
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;
	void OnDrawDebug();
	void LookAtTarget();
	void MoveToTarget();
	void FindLookAtRotation();

};
