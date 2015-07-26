// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "EnergyGenerator.h"



AEnergyGenerator::AEnergyGenerator()
{
    powerRadius = 15.0;
    powerRadiusSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PowerRadiusSphere"));
    powerRadiusSphere->AttachParent = RootComponent;
    powerRadiusSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnergyGenerator::OnOverlapBegin);
    powerRadiusSphere->OnComponentEndOverlap.AddDynamic(this, &AEnergyGenerator::OnOverlapEnd);
    powerRadiusSphere->InitSphereRadius(powerRadius);
    UE_LOG(LogTemp, Warning, TEXT("EnergyGenerator constructed"));
}

bool AEnergyGenerator::ProvidesPower() const
{
    return true;
}

void AEnergyGenerator::OnOverlapBegin(class AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
        bool bFromSweep, const FHitResult& SweepResult)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap beginning"));
    if (OtherActor && OtherComp && OtherActor != this) {
        APowerableBuilding *building = dynamic_cast<APowerableBuilding *>(OtherActor);
        if (building != NULL && building->RequiresPower()) {
            dependentBuildings.AddUnique(building);
            if (!deactivated)
                building->Power();
        }
    }
}

void AEnergyGenerator::OnOverlapEnd(class AActor* OtherActor,
        UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    UE_LOG(LogTemp, Warning, TEXT("Overlap ended"));
    if (OtherActor && OtherComp && OtherActor != this) {
        APowerableBuilding *building = dynamic_cast<APowerableBuilding *>(OtherActor);
        if (building != NULL) {
            if (dependentBuildings.Remove(building) && !deactivated)
                building->UnPower();
        }
    }
}

bool AEnergyGenerator::Activate()
{
    if (deactivated)
        deactivated = false;
        
        for (int i = 0; i < dependentBuildings.Max(); i++) {
            dependentBuildings[i]->Power();
    }
    
    return !deactivated;
}

void AEnergyGenerator::Deactivate()
{
    if (deactivated)
        return; //may want to throw an error here
    
    deactivated = true;
    
    for (int i = 0; i < dependentBuildings.Max(); i++) {
        dependentBuildings[i]->UnPower();
    }
}