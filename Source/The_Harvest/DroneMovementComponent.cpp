// Fill out your copyright notice in the Description page of Project Settings.

#include "The_Harvest.h"
#include "DroneMovementComponent.h"




UDroneMovementComponent::UDroneMovementComponent(){
	PrimaryComponentTick.bCanEverTick = true;
	DefaultLandMovementMode = MOVE_Flying;
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

	if (bIsAscending){
		Velocity.Z = verticalMaxVelocity;
	}
	else if (bIsDescending){
		Velocity.Z = -verticalMaxVelocity;
	}

}

void UDroneMovementComponent::BeginPlay(){
	SetMovementMode(MOVE_Flying);
	UE_LOG(LogTemp, Warning, TEXT("Braking accel: %f"), BrakingDecelerationFlying);
	UE_LOG(LogTemp, Warning, TEXT("MoveType: %s"), *GetMovementName());
	UE_LOG(LogTemp, Warning, TEXT("vertical velocity max: %f"), verticalMaxVelocity);
	UE_LOG(LogTemp, Warning, TEXT("Velocity.Z set to %f"), Velocity.Z);
}