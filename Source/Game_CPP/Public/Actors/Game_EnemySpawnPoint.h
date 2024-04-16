// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Character/Game_Enemy.h"
#include "Game_EnemySpawnPoint.generated.h"

class AGame_AIController;
class AGame_Enemy;

enum E_EenmyType;

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

	
    
   /*
    * AI生成
    */
	UFUNCTION(BlueprintCallable)
	void SpawnEnemy();
	void SpawnAIPC(FVector NewSpawnPoint);

	//生成速率
	float SpawnSpeed = 1;
	//生成类型
  	E_EnemyType NewType = E_EnemyType::SmallEnemy;
	
};
