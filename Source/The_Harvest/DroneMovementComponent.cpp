// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "DroneMovementComponent.h"




UDroneMovementComponent::UDroneMovementComponent(){
	PrimaryComponentTick.bCanEverTick = true;
	
}

void UDroneMovementComponent::Ascend(){
	bIsDescending = false;
	bIsAscending = true;
}

void UDroneMovementComponent::Descend(){
	bIsAscending = false;
	bIsDescending = true;
}

void UDroneMovementComponent::StopAscending(){
	bIsAscending = false;
}

void UDroneMovementComponent::StopDescending(){
	bIsDescending = false;
}

void UDroneMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction){

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SetMovementMode(MOVE_Falling);
	UE_LOG(LogTemp, Warning, TEXT("vertical Max Velocity Set to %f"), verticalMaxVelocity);
	if (TickType != LEVELTICK_All) return;
	if (bIsAscending){
		//UE_LOG(LogTemp, Warning, TEXT("Component Ascending."));
		Velocity.Z = verticalMaxVelocity;
		
	}
	else if (bIsDescending){
		//UE_LOG(LogTemp, Warning, TEXT("Component Descending."));
		Velocity.Z = -verticalMaxVelocity;

	}
	else{
		//UE_LOG(LogTemp, Warning, TEXT("Component Neutral"));
		Velocity.Z = 0.f;
	}

	UE_LOG(LogTemp, Warning, TEXT("Velocity.Z set to %f"),Velocity.Z);
}