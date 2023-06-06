// Copyright Epic Games, Inc. All Rights Reserved.

#include "Examen2MGNGGameMode.h"
#include "Examen2MGNGCharacter.h"
#include "UObject/ConstructorHelpers.h"

AExamen2MGNGGameMode::AExamen2MGNGGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
