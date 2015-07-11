// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/CharacterMovementComponent.h"
#include "DroneMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class THE_HARVEST_API UDroneMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:
	UDroneMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Drone)
	float verticalMaxVelocity = 1000.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Drone)
	float verticalAcceleration = 10.f;

	void Ascend();

	void StopAscending();

	void Descend();

	void StopDescending();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

private:
	bool bIsAscending = false;

	bool bIsDescending = false;
};
