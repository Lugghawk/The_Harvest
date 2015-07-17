// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "ResourceContainer.h"





void UResourceContainer::AddResource(FResourcePile resourcePile){
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