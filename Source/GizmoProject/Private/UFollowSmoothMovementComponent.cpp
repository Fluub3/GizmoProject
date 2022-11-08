// Fill out your copyright notice in the Description page of Project Settings.


#include "UFollowSmoothMovementComponent.h"
#include "LogUtils.h"
#include "LogGizmo.h"

UUFollowSmoothMovementComponent::UUFollowSmoothMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UUFollowSmoothMovementComponent::MoveToTarget_Implementation()
{
	//
	// GetClass()->ImplementsInterface(UIMove::StaticClass());
	// // IF TRUE
	// TScriptInterface<IIMove> _int;
	// _int.SetInterface(Cast<IIMove>(this));
	// if (_int != nullptr)
	// 	_int->Execute_MoveToTarget(this);

	//IIMove::MoveToTarget();
	
	if (!IsValidComponent() || settings.IsAtRange(CurrentPosition()))
	{
		return;
	}
	const FVector _move = FMath::Lerp(CurrentPosition(), settings.TargetPosition(), settings.speed * GetWorld()->DeltaTimeSeconds);
	GetOwner()->SetActorLocation(_move);
}

void UUFollowSmoothMovementComponent::DrawDebug()
{
	const UWorld* _w = GetWorld();
	if (!IsValidComponent())
	{
		DrawDebugBox(_w, CurrentPosition(), FVector(100), FColor::Red);
		return;
	}
	DrawDebugLine(_w, CurrentPosition(), settings.TargetPosition(), FColor::Green);
	DrawDebugSphere(_w, CurrentPosition(), 100, 12, FColor::Green);
	DrawDebugSphere(_w, settings.TargetPosition(), 100, 12, FColor::Yellow);
	DrawDebugCircle(_w, settings.TargetPosition(), 100, 12, FColor::Magenta, false, -1, 0, 2, FVector(1,0,0), FVector(0, 1, 0));
}

void UUFollowSmoothMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("OK"));
	LOG("LOG");
	LOG_WARNING("W");
	LOG_ERROR("ERR");
	SCREEN_MSG("TEST_MACRO", 5, FColor::Blue);

}

void UUFollowSmoothMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	MoveToTarget_Implementation();
	DrawDebug();
	DRAW_SPHERE(FVector::Zero(), 5, FColor::Red);
	DRAW_LINE(CurrentPosition(), FVector(10, 10, 0), FColor::Magenta);
	DRAW_CUBE(FVector(-10, 0, 0), FVector(2, 2, 2), FColor::Green);
}