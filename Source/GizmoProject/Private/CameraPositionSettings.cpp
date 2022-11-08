// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPositionSettings.h"

FVector UCameraPositionSettings::GetCameraPosition(const AActor* _target) const
{
	return offset.useLocalOffset ? offset.GetLocalOffset(_target) : _target->GetActorLocation() + offset.Offset();
}

void UCameraPositionSettings::DrawCameraPosition(const UWorld* _world, const FTransform& _target)
{
	DrawDebugBox(_world, _target.GetLocation(), FVector(100), FColor::Yellow);

}

void UCameraPositionSettings::DrawMoveToStatus(FVector _origin)
{
}