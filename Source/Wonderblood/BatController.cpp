// Copyright pending


#include "BatController.h"

void ABatController::BeginPlay()
{
	Super::BeginPlay();

	SetControlRotation(FRotator(-20.0f, 0.0f, 0.0f));
}

void ABatController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}
