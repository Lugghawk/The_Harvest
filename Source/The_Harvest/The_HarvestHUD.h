// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once 
#include "GameFramework/HUD.h"
#include "The_HarvestHUD.generated.h"

UCLASS()
class AThe_HarvestHUD : public AHUD
{
	GENERATED_BODY()

public:
	AThe_HarvestHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

