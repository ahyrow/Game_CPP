// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Game_Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"


AGame_Character::AGame_Character()
{

	PrimaryActorTick.bCanEverTick = true;
	


	
}

void AGame_Character::BeginPlay()
{
	Super::BeginPlay();
}

void AGame_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

