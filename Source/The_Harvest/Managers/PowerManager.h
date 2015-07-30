// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "../Buildings/EnergyGenerator.h"
#include "PowerManager.generated.h"

/**
 * 
 */
UCLASS()
class THE_HARVEST_API UPowerManager : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly)
	float currentCapacity;

	UPROPERTY(BlueprintReadOnly)
	float totalCapacity;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<AEnergyGenerator*> generators;
	
	/*
		Cycles through all registered generators and distributes their power among all covered, powerable buildings.
	*/
	UFUNCTION(BlueprintCallable, Category="Power")
	void checkPower();

	UFUNCTION(BlueprintCallable, Category = "Power")
	void registerGenerator(AEnergyGenerator* generator);

	UFUNCTION(BlueprintCallable, Category = "Power")
	void deregisterGenerator(AEnergyGenerator* generator);
	
};
