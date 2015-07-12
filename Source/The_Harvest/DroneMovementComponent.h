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
	float verticalMaxVelocity = 600.f;

	void Ascend();

	void StopAscending();

	void Descend();

	void StopDescending();

	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction) override;

	void BeginPlay() override;

private:
	bool bIsAscending = false;

	bool bIsDescending = false;
};
