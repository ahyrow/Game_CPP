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

	//怪物向玩家移动
	void AIMovePlayer();

	//等待时间
	void WaitTime(float Seconds);

	//等待时间结束回调
	void OnWaitFinished();

public:
    //是否移动
	bool bIsMove=true;
	//移动碰撞半径
	float AcceptanceRadius;
};
