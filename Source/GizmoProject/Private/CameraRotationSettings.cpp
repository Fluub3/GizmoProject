// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraRotationSettings.h"

void UCameraRotationSettings::DrawLookAtStatus(const UWorld* _world, const FVector& _origin)
{
	if (!drawGizmos)
		return;
	DrawDebugSphere(_world, _origin + FVector::UpVector * 200, 50, 12, useLookAt ? validRotationToColor : FColor::Red);
	DrawDebugLine(_world, _origin + FVector::UpVector * 200, _origin, FColor::White);
}

void UCameraRotationSettings::DrawLookAtTarget(const UWorld* _world, FVector _targetPosition, FVector _origin, FColor _color)
{
	DrawDebugSphere(_world, _targetPosition, 15, 12, _color);
	DrawDebugLine(_world, _targetPosition, _origin, _color);
}

FVector UCameraRotationSettings::GetLookAtTarget(const AActor* _target) const
{
	if (!_target)
		return offset.Offset();

	return offset.useLocalOffset ? offset.GetLocalOffset(_target) : _target->GetActorLocation() + offset.Offset();
}
