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

   //角色死亡 
	void PlayerDie();
	/*
	 * 玩家经验值
	 */
	//当前经验
    float CurrentExp = 0;
	//最大经验值
	float  MaxExp = 100;
	//玩家等级
	int32 Level = 1;
	//怪物经验
	int32 EnemiesExp;

	void  PlayerEXP();
	
	
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

	
	/*基础技能*/
	/*UPROPERTY(EditAnywhere,Category="SkillAsset")
	TSubclassOf<AGame_Bullet> BulletClass;*/
	int32 SkillPoint;
	void BaseSKill();
	
	float SpawnTime = 1 ;
	
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UGame_AbilitySystemComponent> AbilitySystemComponent;
};


