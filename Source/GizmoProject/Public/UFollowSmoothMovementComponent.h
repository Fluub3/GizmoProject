// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FMyStruct.h"
#include "IMove.h"
#include "Components/ActorComponent.h"
#include "UFollowSmoothMovementComponent.generated.h"

USTRUCT(BlueprintType, Blueprintable)
struct FMovementSettings
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TObjectPtr<AActor> target = nullptr;

	UPROPERTY(EditAnywhere, meta = (UIMin = 0, UIMax = 1000, ClampMin = 0, ClampMax = 1000))
	float speed = 10;
	
	UPROPERTY(EditAnywhere, meta = (UIMin = 0, UIMax = 1000, ClampMin = 0, ClampMax = 1000))
	float range = 100;
	
	UPROPERTY(EditAnywhere)
	bool bIsPause = false;
	
	FMovementSettings() {}
	
	FMovementSettings(TObjectPtr<AActor> _target)
	{
		target = _target;
		speed = FMath::Clamp(1, 0, 10);
		range = FMath::Clamp(1, 0, 10);
		bIsPause = false;
	}

	FORCEINLINE FVector TargetPosition()
	{
		if (target.Get() != nullptr)
			return target.Get()->GetActorLocation();
		return FVector(0);
	}

	FORCEINLINE bool IsAtRange(FVector _origin)
	{
		return FVector::Distance(_origin, target->GetActorLocation()) < range ;
	}

	void SetTarget(TObjectPtr<AActor> _target) { target = _target;}
	void SetSpeed(float _speed) { speed = _speed;}
	void StopMovement() { bIsPause = true;}
	void ResumeMovement() { bIsPause = false;}
	
	
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GIZMOPROJECT_API UUFollowSmoothMovementComponent : public UActorComponent, public IIMove
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, Category = "Movement Settings")
	FMovementSettings settings;

	UPROPERTY(EditAnywhere, Category = "Movement Settings")
	FMyStruct gizmoSettings;

public:	
	UUFollowSmoothMovementComponent();
	FORCEINLINE FMovementSettings& Settings() {return settings;};
	FORCEINLINE FVector CurrentPosition() const { return GetOwner()->GetActorLocation();}
	FORCEINLINE bool IsValidComponent() const { return settings.target != nullptr;}

#pragma region IMOVE
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = Movement)
	void MoveToTarget();
	void MoveToTarget_Implementation() override;
#pragma endregion 


private:
	//void MoveToTarget();
	void DrawDebug();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
