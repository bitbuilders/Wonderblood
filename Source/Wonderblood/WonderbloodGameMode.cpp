// Copyright Epic Games, Inc. All Rights Reserved.

#include "WonderbloodGameMode.h"
#include "WonderbloodCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWonderbloodGameMode::AWonderbloodGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
