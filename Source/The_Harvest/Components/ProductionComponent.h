// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Resources/ResourcePile.h"
#include "ProductionComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THE_HARVEST_API UProductionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UProductionComponent();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	/** is production enabled */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	bool enabled;

	/** can the entity produce things */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	bool canProduce;

	/** rate of production */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	int32 productionRate;

	/** Resource being produced */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	struct FResourceData producedResource;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
	UResourceContainer *resourceContainer;

	/** Time required for a production cycle */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	int32 productionCycleTime;

	/** Time since last production completed */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Production")
	float secondsSinceLastCycle;
	
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void SetResourceContainer(UResourceContainer *container);
};
