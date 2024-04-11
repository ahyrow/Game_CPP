// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game_Character.generated.h"



class UCameraComponent;
class USpringArmComponent;


UCLASS()
class GAME_CPP_API AGame_Character : public ACharacter
{
	GENERATED_BODY()

public:

AGame_Character();

virtual void Tick(float DeltaSeconds) override;	

public:

    UPROPERTY(EditAnywhere,Category="Component")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere,Category="Component")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditAnywhere,Category="Static Mesh")
	TObjectPtr<UStaticMeshComponent> WirteBoxPlayer;

public:

	void UpdatePlayerRotationToMouse();
};


