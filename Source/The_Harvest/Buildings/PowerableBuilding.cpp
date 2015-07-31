// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "PowerableBuilding.h"

APowerableBuilding::APowerableBuilding()
{
    numPowerSources = 0;
    isPowered = false;
	poweredText = CreateDefaultSubobject<UTextRenderComponent>("PoweredText");
	poweredText->AddLocalOffset(FVector(0, 0, 650));
	poweredText->SetXScale(5.f);
	poweredText->SetYScale(5.f);
	poweredText->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	poweredText->SetText(TEXT("UNPOWERED"));
}

bool APowerableBuilding::RequiresPower() const
{
    return true;
}

void APowerableBuilding::Power()
{
    numPowerSources++;
    isPowered = true;
	poweredText->SetText(TEXT("POWERED"));
}

void APowerableBuilding::UnPower()
{
    if (--numPowerSources <= 0) {
        isPowered = false;
        numPowerSources = 0;
		poweredText->SetText(TEXT("UNPOWERED"));
    }
}
