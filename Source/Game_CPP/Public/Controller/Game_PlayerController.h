// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Game_PlayerController.generated.h"


class UGame_IA_PlayerMove;
class UGame_IMC;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;
/**
 * 
 */
UCLASS()
class GAME_CPP_API AGame_PlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	AGame_PlayerController();

public:


	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputMappingContext> GameContext;

	UPROPERTY(EditAnywhere,Category="Input")
	TObjectPtr<UInputAction> PlayerMoveAction;



	
public:
    
	virtual void BeginPlay() override;
	
	virtual void SetupInputComponent() override;
public:
    //移动回调
	void PlayerMove(const FInputActionValue& InputActinValue);
	
};
