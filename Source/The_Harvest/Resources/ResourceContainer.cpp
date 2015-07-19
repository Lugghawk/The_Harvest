// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "ResourceContainer.h"



UResourceContainer::UResourceContainer(){
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;//Invetories don't need to tick.. right?
}

bool UResourceContainer::AddResource(FResourcePile resourcePile){
	if ((GetTotalResourceAmount() + resourcePile.amount) > Capacity){
		return false;
	}
	FResourcePile* pile = FindResourcePile(resourcePile.resourceName);
	if ( pile != nullptr){
		//Resource exists in our pile already, just add to it.
		pile->amount += resourcePile.amount;
		resourcePile.amount = 0; //Set it to zero so any future manipulations with it shouldn't have an effect.
	}
	else
	{
		resources.Add(resourcePile);
	}
	return true;
}


FResourcePile* UResourceContainer::FindResourcePile(FName name){
	for (int32 i = 0; i < resources.Num(); i++){
		if ( resources[i].resourceName.IsEqual(name) ){
			return &resources[i];
		}
	}
	return nullptr;
}

int32 UResourceContainer::GetTotalResourceAmount(){
	int32 amount = 0;
	for (int32 i = 0; i < resources.Num(); i++){
		amount += resources[i].amount;
	}
	return amount;
}

TArray<FResourcePile> UResourceContainer::GetResources(){
	return resources;
}

// Called when the game starts
void UResourceContainer::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Won't be called right now
// See PrimaryComponentTick.bCanEverTick in constructor.
void UResourceContainer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

