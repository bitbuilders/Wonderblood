// Copyright pending

#pragma once

#include "CoreMinimal.h"
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

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UPawnMovementComponent* Movement;
};
