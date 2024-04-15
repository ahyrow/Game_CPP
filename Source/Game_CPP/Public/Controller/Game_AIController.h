// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Game_AIController.generated.h"

/**
 * 
 */
UCLASS()
class GAME_CPP_API AGame_AIController : public AAIController
{
	GENERATED_BODY()
	

public:


	AGame_AIController();
	virtual void Tick(float DeltaSeconds) override;
    virtual void BeginPlay() override;
public:

	void AIMovePlayer();

	void WaitTime(float Seconds);

	void OnWaitFinished();

public:

	bool bIsMove=true;
	float AcceptanceRadius;
};
