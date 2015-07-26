// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Resources/ResourceContainer.h"
#include "Components/ProductionComponent.h"
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
    UFUNCTION(BlueprintCallable, Category="Power")
    virtual bool RequiresPower() const;
    
    /** does the building provide power? */
    UFUNCTION(BlueprintCallable, Category="Power")
    virtual bool ProvidesPower() const;
    
    /** place the building, returns true if placement was successful */
    UFUNCTION(BlueprintCallable, Category="Placement")
    virtual void PlaceBuilding(bool& successful);

    /** add some resources to the building's container */
    UFUNCTION(BlueprintCallable, Category="Inventory")
    virtual bool AddResource(struct FResourcePile pile);
    
    /** returns the production component attached to the building */
	UFUNCTION(BlueprintCallable, Category = "Production")
	virtual UProductionComponent *GetProductionComponent();

    /** deactivates the building */
    UFUNCTION(BlueprintCallable, Category = "General")
    virtual void Deactivate();
    
    /** attempts to activate the building, returns true if successful */
    UFUNCTION(BlueprintCallable, Category = "General")
    virtual bool Activate();

    /** set the building mesh */
    UFUNCTION(BlueprintCallable, Category = "General")
    UStaticMeshComponent *SetBuildingMesh(UStaticMesh *mesh);

    
    /** has the building been properly placed */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Placement")
    bool placed;

    /** is the building turned off by the player */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="General")
    bool deactivated;
  
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Inventory")
    UResourceContainer *resourceContainer;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Production")
    UProductionComponent *productionComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	FName HUDBuildingName;
    
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HUD")
	UTexture2D *HUDTexture;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Appearance")
    UStaticMeshComponent *buildingMesh;

};
