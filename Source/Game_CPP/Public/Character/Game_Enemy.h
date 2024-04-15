// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game_Enemy.generated.h"

//class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;
class AGame_AIController;

enum class E_EnemyType:int8
{
    BigEnemy,
	MiddleEnemy,
	SmallEnemy
	
};

struct FEnemyInfo
{
	float CurrentHealth;
	float MaxHealth;
	float Damage;
    float EnemyMoveSpeed;
    float SpawnFrequency;
	//骨骼 动画等
};


UCLASS()
class GAME_CPP_API AGame_Enemy : public ACharacter
{
	GENERATED_BODY()

public:
	
	AGame_Enemy();

protected:
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;


	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);
	
	
public:

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> EnemyStaticMesh;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> Sphere;

	
	/*UPROPERTY(EditAnywhere)
	TObjectPtr<UWidgetComponent> EnemyLifeWidget;*/
public:

    TSubclassOf<AGame_AIController> AIControllerClass;	
	
	UPROPERTY(BlueprintReadWrite)
	float EnemyMoveSpeed = 150;

	//默认伤害
	float DamageToPlayer=5.f;


	
	//敌人类型
	E_EnemyType EnemyType=E_EnemyType::SmallEnemy;
	//信息
	FEnemyInfo EnemyInfo;
    //设置敌人信息
	void SetEnemyInfo (E_EnemyType EnemyType);
    //设置敌人类型
	void SetEnemyType(int32 GameTime);

	void UpDateEnemyHealth(float Damage);
};