// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "HarvestFunctionLib.h"




UObject* UHarvestFunctionLib::GetDefaultObject(TSubclassOf<UObject> ObjectClass){
	return ObjectClass->GetDefaultObject();
}