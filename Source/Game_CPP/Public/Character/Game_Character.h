// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game_Character.generated.h"


class UGame_AbilitySystemComponent;
class AGame_Bullet;
class UCameraComponent;
class USpringArmComponent;
class UStaticMesh;

UCLASS()
class GAME_CPP_API AGame_Character : public ACharacter
{
	GENERATED_BODY()

public:

    AGame_Character();

    virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

public:

    UPROPERTY(EditAnywhere,Category="Component")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	UPROPERTY(EditAnywhere,Category="Component")
	TObjectPtr<UCameraComponent> CameraComponent;

	UPROPERTY(EditAnywhere,Category="Static Mesh")
	TObjectPtr<UStaticMeshComponent> WirteBoxPlayer;

public:

	void UpdatePlayerRotationToMouse();

	void HealthLoss(float Damage);


public:
  /*PlayerHealth*/
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float PlayerCurrentHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float PlayerMaxHealth;

	void PlayerDie();


	/*kill*/
	/*UPROPERTY(EditAnywhere,Category="SkillAsset")
	TSubclassOf<AGame_Bullet> BulletClass;*/
	void BaseSKill();
	
	float SpawnTime = 1 ;
	
	//计时
	//分
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	int32 Minute;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	//秒
	int32 Second;

	//时间计算
	void Timekeeping();

	/*
	 *  根据游戏时间生成AI
	 */

	
	class AGame_EnemySpawnPoint* EnemySpawnPoint;


	/*
	 * 技能系统组件
	 */
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGame_AbilitySystemComponent> AbilitySystemComponent;
};


