// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Buildings/Building.h"
#include "Buildings/PowerableBuilding.h"
#include "EnergyGenerator.generated.h"

/**
 * 
 */
UCLASS()
class THE_HARVEST_API AEnergyGenerator : public ABuilding
{
	GENERATED_BODY()

public:
	AEnergyGenerator();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
    float powerRadius;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
	USphereComponent *powerRadiusSphere;
	
    TArray<APowerableBuilding *> dependentBuildings;
	
    UFUNCTION()
    void OnOverlapBegin(class AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
            bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnOverlapEnd(class AActor* OtherActor,
            UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

    /** does the building provide power? */
    UFUNCTION(BlueprintCallable, Category="Power")
    virtual bool ProvidesPower() const;
            
    /** deactivates the building */
    UFUNCTION(BlueprintCallable, Category = "Production")
    virtual void Deactivate();
    
    /** attempts to activate the building, returns true if successful */
    UFUNCTION(BlueprintCallable, Category = "General")
    virtual bool Activate();
};
