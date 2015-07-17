// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Engine/DataTable.h"
#include "Resource.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class THE_HARVEST_API UResource : public UObject
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName ResourceName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	uint32 bIsEnergy : 1;
	
};


