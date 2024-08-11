// Copyright pending


#include "Bat.h"

#include "BatMovement.h"
#include "GameFramework/PawnMovementComponent.h"

ABat::ABat()
{
	PrimaryActorTick.bCanEverTick = true;

	Movement = CreateDefaultSubobject<UBatMovement>(TEXT("BatMovementComponent"));
}

void ABat::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

