// Copyright pending

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BatController.generated.h"

/**
 * 
 */
UCLASS()
class WONDERBLOOD_API ABatController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;
};
