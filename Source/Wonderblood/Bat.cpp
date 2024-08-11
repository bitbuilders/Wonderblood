// Copyright pending

#include "Bat.h"

#include "GameFramework/PawnMovementComponent.h"

ABat::ABat()
{
	PrimaryActorTick.bCanEverTick = true;

	Movement = Cast<UPawnMovementComponent>(CreateDefaultSubobject(TEXT("PawnMovement"), UPawnMovementComponent::StaticClass(), MovementClass.Get(), true, false));
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

