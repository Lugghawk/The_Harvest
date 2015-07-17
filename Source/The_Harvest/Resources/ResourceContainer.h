// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "ResourcePile.h"
#include "ResourceContainer.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class THE_HARVEST_API UResourceContainer : public UObject
{
	GENERATED_BODY()

protected:
	FResourcePile* FindResourcePile(FName name);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FResourcePile> resources;

	UFUNCTION(BlueprintCallable, Category = Resources)
	void AddResource(FResourcePile resourcePile);

	UFUNCTION(BlueprintCallable, Category = Resources)
	int32 GetTotalResourceAmount();
};
