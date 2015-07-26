// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "PowerableBuilding.h"

APowerableBuilding::APowerableBuilding()
{
    numPowerSources = 0;
    isPowered = false;
}

bool APowerableBuilding::RequiresPower() const
{
    return true;
}

void APowerableBuilding::Power()
{
    numPowerSources++;
    isPowered = true;
}

void APowerableBuilding::UnPower()
{
    if (--numPowerSources <= 0) {
        isPowered = false;
        numPowerSources = 0;
    }
}
