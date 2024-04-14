// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game_EnemySpawnPoint.generated.h"

class AGame_Enemy;

UCLASS()
class GAME_CPP_API AGame_EnemySpawnPoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGame_EnemySpawnPoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

   
	
	FVector SpawnPoint;

	UFUNCTION(BlueprintCallable)
	void SpawnEnemy();

	//void TimerCallBack();
};
