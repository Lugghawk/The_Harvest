// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Building.generated.h"

UCLASS()
class THE_HARVEST_API ABuilding : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilding();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

    /** does the building require power to operate */
    UFUNCTION(BlueprintCallable, Category="Electrical")
    virtual bool RequiresPower() const;
    
    /** does the building provide power? */
    UFUNCTION(BlueprintCallable, Category="Electrical")
    virtual bool ProvidesPower() const;
    
    /** place the building, returns true if placement was successful */
    UFUNCTION(BlueprintCallable, Category="Placement")
    virtual void PlaceBuilding(bool& successful);

    /** has the building been properly placed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Placement")
    bool Placed;

    /** is the building turned off by the player */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Power")
    bool Deactivated;
};
