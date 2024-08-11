// Copyright pending


#include "Bat.h"

#include "BatMovement.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
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

void ABat::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
}

void ABat::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABat::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(InputMapping, 0);

	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	Input->BindAction(FlapAction, ETriggerEvent::Triggered, this, &ABat::Flap);
	Input->BindAction(FlyAction, ETriggerEvent::Triggered, this, &ABat::Fly);
	Input->BindAction(StrafeAction, ETriggerEvent::Triggered, this, &ABat::Strafe);
	Input->BindAction(BrakeAction, ETriggerEvent::Triggered, this, &ABat::Brake);
	Input->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABat::Look);
}

void ABat::Flap(const FInputActionValue& Value)
{
	UPrimitiveComponent* Body = Cast<UPrimitiveComponent>(GetRootComponent());

	Body->AddImpulse(RotateInput(FVector::UpVector) * 100000.0f);
}

void ABat::Fly(const FInputActionValue& Value)
{
	AddMovementInput(RotateInput(FVector::ForwardVector));
}

void ABat::Strafe(const FInputActionValue& Value)
{
	AddMovementInput(RotateInput(FVector::RightVector) * Value.Get<float>());
}

void ABat::Brake(const FInputActionValue& Value)
{
	AddMovementInput(RotateInput(FVector::BackwardVector));
}

void ABat::Look(const FInputActionValue& Value)
{
	FVector2D Input = Value.Get<FVector2D>();
	AddControllerPitchInput(-Input.Y);
	AddControllerYawInput(Input.X);
}

FRotator ABat::InputRotator() const
{
	return FRotator(0.0f, GetControlRotation().Yaw, 0.0f);
}

FVector ABat::RotateInput(FVector Input) const
{
	return InputRotator().RotateVector(Input);
}

