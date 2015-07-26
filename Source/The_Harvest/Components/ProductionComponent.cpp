// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "ProductionComponent.h"


// Sets default values for this component's properties
UProductionComponent::UProductionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	canProduce = true;
	enabled = false;
	secondsSinceLastCycle = 0.0;
	productionCycleTime = 5;
	productionRate = 1;
	resourceContainer = NULL;
}


// Called when the game starts
void UProductionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UProductionComponent::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

void UProductionComponent::SetResourceContainer(UResourceContainer *container)
{
	resourceContainer = container;
}