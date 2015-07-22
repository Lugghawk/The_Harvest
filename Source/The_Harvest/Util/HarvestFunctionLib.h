// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "HarvestFunctionLib.generated.h"

/**
 * 
 */
UCLASS()
class THE_HARVEST_API UHarvestFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Object")
	static UObject* GetDefaultObject(TSubclassOf<UObject> ObjectClass);
	
	
};
