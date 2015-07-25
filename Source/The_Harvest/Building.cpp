// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "Building.h"


// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    Placed = false;
    Deactivated = true;
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABuilding::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

bool ABuilding::RequiresPower() const {
    return false;
}

bool ABuilding::ProvidesPower() const
{
    return false;
}

void ABuilding::PlaceBuilding(bool& successful)
{
    Placed = true;
    successful = Placed;
}