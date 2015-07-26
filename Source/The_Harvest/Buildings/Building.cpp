// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "Building.h"


// Sets default values
ABuilding::ABuilding()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	placed = false;
	deactivated = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	resourceContainer = CreateDefaultSubobject<UResourceContainer>(TEXT("InventoryComponent"));
    productionComponent = CreateDefaultSubobject<UProductionComponent>(TEXT("ProductionComponent"));
    productionComponent->SetResourceContainer(resourceContainer);
    
    buildingMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BuildingMesh"));
    buildingMesh->bAutoRegister = true;
    buildingMesh->AttachParent = RootComponent;
    HUDBuildingName = "DefaultName";
    HUDTexture = NULL;
    
    UE_LOG(LogTemp, Warning, TEXT("Building constructed"));
    
}

UStaticMeshComponent *ABuilding::SetBuildingMesh(UStaticMesh *mesh)
{
    buildingMesh->SetStaticMesh(mesh);
    return buildingMesh;
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

bool ABuilding::AddResource(struct FResourcePile pile)
{
    UE_LOG(LogTemp, Warning, TEXT("adding resource to container"));
    return resourceContainer->AddResource(pile);
}

bool ABuilding::RequiresPower() const
{
	return false;
}

bool ABuilding::ProvidesPower() const
{
	return false;
}

bool ABuilding::Activate()
{
    deactivated = false;
    
    return true;
}

void ABuilding::Deactivate()
{
    deactivated = true;
}

void ABuilding::PlaceBuilding(bool& successful)
{
    UE_LOG(LogTemp, Warning, TEXT("building placed"));
	placed = true;
	successful = placed;
}

UProductionComponent *ABuilding::GetProductionComponent()
{
	return productionComponent;
}