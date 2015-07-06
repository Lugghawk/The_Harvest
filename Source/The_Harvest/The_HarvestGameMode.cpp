// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "The_Harvest.h"
#include "The_HarvestGameMode.h"
#include "The_HarvestHUD.h"
#include "The_HarvestCharacter.h"

AThe_HarvestGameMode::AThe_HarvestGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AThe_HarvestHUD::StaticClass();
}
