// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Object.h"
#include "ResourcePile.h"
#include "ResourceContainer.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class THE_HARVEST_API UResourceContainer : public UActorComponent
{
	GENERATED_BODY()

protected:
	FResourcePile* FindResourcePile(FName name);

	TArray<FResourcePile> resources;

public:


	UResourceContainer();


	UFUNCTION(BlueprintCallable, Category = Resources)
	TArray<FResourcePile> GetResources();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = Resources)
	int32 Capacity;

	/* True if the resource was added, false if the capacity would have been exceeded. */
	UFUNCTION(BlueprintCallable, Category = Resources)
	bool AddResource(FResourcePile resourcePile);

	UFUNCTION(BlueprintCallable, Category = Resources)
	int32 GetTotalResourceAmount();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;



};
