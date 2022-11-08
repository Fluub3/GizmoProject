#include "CameraTPS.h"
#include "Kismet/KismetMathLibrary.h"

ACameraTPS::ACameraTPS()
{
	PrimaryActorTick.bCanEverTick = true;
	cameraTarget = CreateDefaultSubobject<UCameraComponent>("Camera");
	RootComponent = cameraTarget;
	//lookAtSettings = CreateDefaultSubobject<UCameraRotationSettings>("LookAtSettings");
	//moveToSettings = CreateDefaultSubobject<UCameraPositionSettings>("MoveToSettings");
}

void ACameraTPS::InitCamera()
{
	GetWorld()->GetFirstPlayerController()->SetViewTarget(this);
}

void ACameraTPS::BeginPlay()
{
	Super::BeginPlay();
	InitCamera();
}

void ACameraTPS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	OnDrawDebug();
	MoveToTarget();
	LookAtTarget();

}

void ACameraTPS::OnDrawDebug()
{
	if (!lookAtSettings)
		return;
	lookAtSettings->DrawLookAtStatus(GetWorld(), GetActorLocation());
	lookAtSettings->DrawLookAtTarget(GetWorld(), CurrentTargetLocation(), CurrentCameraLocation(), FColor::Red);
	moveToSettings->DrawCameraPosition(GetWorld(), GetTransform());
}
void ACameraTPS::LookAtTarget()
{
	const FRotator& _rot = UKismetMathLibrary::FindLookAtRotation(CurrentCameraLocation(), CurrentTargetLocation());
	const FRotator& _final = lookAtSettings->UseSmoothLookAt() ?
		FMath::RInterpTo(CurrentCameraRotation(), _rot, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed()) :
		FMath::RInterpConstantTo(CurrentCameraRotation(), _rot, GetWorld()->DeltaTimeSeconds, lookAtSettings->RotationSpeed());
	SetActorRotation(_final);

}

void ACameraTPS::MoveToTarget()
{
	if (!moveToSettings->UseMoveTo())
		return;
	const FVector& _location = moveToSettings->UseSmoothMove() ?
		FMath::VInterpTo(CurrentCameraLocation(), moveToSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, moveToSettings->PositionSpeed()) :
		FMath::VInterpConstantTo(CurrentCameraLocation(), moveToSettings->GetCameraPosition(target), GetWorld()->DeltaTimeSeconds, moveToSettings->PositionSpeed());

	SetActorLocation(_location);
}



