// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#define DRAW_SPHERE(Loc, Size, Color) DrawDebugSphere(GetWorld(), Loc, Size, 12, Color);
#define DRAW_LINE(start, end, color)  DrawDebugLine(GetWorld(), start, end, color);
#define DRAW_CUBE(Loc, Size, Color) DrawDebugBox(GetWorld(), Loc, Size, Color);