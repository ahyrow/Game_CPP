// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game_Enemy.generated.h"

//class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;
class AGame_AIController;

//敌人类型
UENUM(BlueprintType)
enum class E_EnemyType:uint8
{
    BigEnemy UMETA(DisplayName = "BigEnemy"),
	MiddleEnemy UMETA(DisplayName = "MiddleEnemy Enemy"),
	SmallEnemy UMETA(DisplayName = "SmallEnemy Enemy")
};

//敌人属性结构
USTRUCT(BlueprintType)
struct FEnemyInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float CurrentHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float MaxHealth;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float Damage;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
    float EnemyMoveSpeed;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
    float SpawnFrequency;
	//骨骼 动画等
};


UCLASS(Blueprintable)
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
	float EnemyMoveSpeed;

	
	//当前类型
	/*UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	E_EnemyType EnemyType =E_EnemyType::SmallEnemy;*/

	//新的AI类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enemy")
	E_EnemyType NewEnemyType  ;
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Enemy")
	FEnemyInfo EnemyInfo ;
	
    //获取AI信息
	UFUNCTION(BlueprintCallable,Category = "Enemy")
	FEnemyInfo GetEnemyInfo(E_EnemyType _EnemyType);

	//设置AI类型
	void SetEnemyType(int32 GameTime);

	//生命值更新
	void UpDateEnemyHealth(float Damage);

	//设置类型
	void SetEnemyType(E_EnemyType _NewEnemyType);

   /*
    *  属性 
    */
	//
protected:
	float CurrentHealth;
	float MaxHealth;
	float DamageToPlayer;
	float BaseMoveSpeed;
	float CurrentSpawnFrequency;
};