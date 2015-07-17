// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "Resource.h"
#include "Engine/DataTable.h"
#include "ResourcePile.generated.h"

USTRUCT(Blueprintable)
struct FResourcePile
{
	GENERATED_USTRUCT_BODY();
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName resourceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 amount;

};

USTRUCT(BlueprintType)
struct FResourceData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FResourceData()
		:resourceName("NOT SET")
		, isEnergy(false)
	{}


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
	FName resourceName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Resources)
	bool isEnergy;

};
