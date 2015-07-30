// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "PowerManager.h"


void UPowerManager::checkPower(){
	//Nothing right now
}

void UPowerManager::registerGenerator(AEnergyGenerator* generator){
	if (generators.Contains(generator)) return;
	generators.AddUnique(generator);
	totalCapacity += generator->energyProvided;

}

void UPowerManager::deregisterGenerator(AEnergyGenerator* generator){
	if (!generators.Contains(generator)) return;

	generators.Remove(generator);
	totalCapacity -= generator->energyProvided;
}