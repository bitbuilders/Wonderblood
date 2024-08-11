// Copyright pending

#pragma once

#include "CoreMinimal.h"
#include "InputMappingContext.h"
#include "GameFramework/Pawn.h"
#include "Bat.generated.h"

UCLASS()
class WONDERBLOOD_API ABat : public APawn
{
	GENERATED_BODY()

public:
	ABat();

protected:
	virtual void BeginPlay() override;

	virtual void PossessedBy(AController* NewController) override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UFUNCTION()
	void Flap(const FInputActionValue& Value);

	UFUNCTION()
	void Fly(const FInputActionValue& Value);

	UFUNCTION()
	void Strafe(const FInputActionValue& Value);

	UFUNCTION()
	void Brake(const FInputActionValue& Value);

	UFUNCTION()
	void Look(const FInputActionValue& Value);

	FRotator InputRotator() const;

	FVector RotateInput(FVector Input) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPawnMovementComponent* Movement;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputAction* FlyAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputAction* StrafeAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputAction* BrakeAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputAction* FlapAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Input)
	UInputAction* LookAction;
};
