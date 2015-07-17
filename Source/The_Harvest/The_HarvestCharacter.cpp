// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "The_Harvest.h"
#include "The_HarvestCharacter.h"
#include "The_HarvestProjectile.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/InputSettings.h"

DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AThe_HarvestCharacter

AThe_HarvestCharacter::AThe_HarvestCharacter(const class FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer.SetDefaultSubobjectClass<UDroneMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	GetCapsuleComponent()->SetEnableGravity(false);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->AttachParent = GetCapsuleComponent();
	FirstPersonCameraComponent->RelativeLocation = FVector(0, 0, 64.f); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Default offset from the character location for projectiles to spawn
	GunOffset = FVector(100.0f, 30.0f, 10.0f);

	// Note: The ProjectileClass and the skeletal mesh/anim blueprints for Mesh1P are set in the
	// derived blueprint asset named MyCharacter (to avoid direct content references in C++)

	bReplicates = true;
	bReplicateMovement = true;
}

//////////////////////////////////////////////////////////////////////////
// Input

void AThe_HarvestCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	// set up gameplay key bindings
	check(InputComponent);

	InputComponent->BindAction("Ascend", IE_Pressed, this, &AThe_HarvestCharacter::Ascend);
	InputComponent->BindAction("Ascend", IE_Released, this, &AThe_HarvestCharacter::StopAscending);

	InputComponent->BindAction("Descend", IE_Pressed, this, &AThe_HarvestCharacter::Descend);
	InputComponent->BindAction("Descend", IE_Released, this, &AThe_HarvestCharacter::StopDescending);


	
	InputComponent->BindAction("Fire", IE_Pressed, this, &AThe_HarvestCharacter::OnFire);
	
	InputComponent->BindAxis("MoveForward", this, &AThe_HarvestCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AThe_HarvestCharacter::MoveRight);
	
	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	InputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	InputComponent->BindAxis("TurnRate", this, &AThe_HarvestCharacter::TurnAtRate);
	InputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	InputComponent->BindAxis("LookUpRate", this, &AThe_HarvestCharacter::LookUpAtRate);
}

void AThe_HarvestCharacter::Tick(float DeltaTime){

}

void AThe_HarvestCharacter::Ascend(){
	UE_LOG(LogTemp, Warning, TEXT("Char Ascend"));
	//GetDroneMovementComponent()->Ascend();
	SetAscending(true);
}

void AThe_HarvestCharacter::StopAscending(){
	UE_LOG(LogTemp, Warning, TEXT("Char Stop Ascend"));
//	GetDroneMovementComponent()->StopAscending();
	SetAscending(false);
}

void AThe_HarvestCharacter::Descend(){
	UE_LOG(LogTemp, Warning, TEXT("Char Descend"));
	//GetDroneMovementComponent()->Descend();
	SetDescending(true);
}

void AThe_HarvestCharacter::StopDescending(){
	UE_LOG(LogTemp, Warning, TEXT("Char Stop Descend"));
	//GetDroneMovementComponent()->StopDescending();
	SetDescending(false);
}

void AThe_HarvestCharacter::SetAscending(bool ascending){
	if (ascending){
		GetDroneMovementComponent()->Ascend();
	}
	else{
		GetDroneMovementComponent()->StopAscending();
	}
	if (Role < ROLE_Authority){
		ServerSetAscending(ascending);
	}
}

void AThe_HarvestCharacter::ServerSetAscending_Implementation(bool ascending){
	SetAscending(ascending);
}

bool AThe_HarvestCharacter::ServerSetAscending_Validate(bool ascending) { return true; }

void AThe_HarvestCharacter::SetDescending(bool descending){
	if (descending){
		GetDroneMovementComponent()->Descend();
	}
	else{
		GetDroneMovementComponent()->StopDescending();
	}
	if (Role < ROLE_Authority){
		ServerSetDescending(descending);
	}
}

void AThe_HarvestCharacter::ServerSetDescending_Implementation(bool descending){
	SetDescending(descending);
}

bool AThe_HarvestCharacter::ServerSetDescending_Validate(bool descending){ return true; }

void AThe_HarvestCharacter::OnFire()
{ 

}

UDroneMovementComponent* AThe_HarvestCharacter::GetDroneMovementComponent(){
	return Cast<UDroneMovementComponent>(GetCharacterMovement());
}

void AThe_HarvestCharacter::MoveForward(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorForwardVector(), Value);
	}
}

void AThe_HarvestCharacter::MoveRight(float Value)
{
	if (Value != 0.0f)
	{
		// add movement in that direction
		AddMovementInput(GetActorRightVector(), Value);
	}
}

void AThe_HarvestCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AThe_HarvestCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

