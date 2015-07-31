// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Buildings/Building.h"
#include "PowerableBuilding.generated.h"

/**
 * 
 */
UCLASS()
class THE_HARVEST_API APowerableBuilding : public ABuilding
{
	GENERATED_BODY()

public:	
    APowerableBuilding();

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	UTextRenderComponent* poweredText;

    /** adds a power source from the building */
    UFUNCTION(BlueprintCallable, Category="Power")
    void Power();
    
    /** removes a power source from the building */
    UFUNCTION(BlueprintCallable, Category="Power")
    void UnPower();
    
    /** does the building require power to operate */
    UFUNCTION(BlueprintCallable, Category="Power")
    virtual bool RequiresPower() const;
    
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Power")
	bool isPowered;
    
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Power")
    int32 numPowerSources;
};
