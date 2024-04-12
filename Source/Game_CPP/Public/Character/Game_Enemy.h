// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Game_Enemy.generated.h"

//class UWidgetComponent;
class UStaticMeshComponent;
class USphereComponent;

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
	
	UPROPERTY(BlueprintReadWrite)
	float EnemyMoveSpeed = 150;

	float DamageToPlayer=5.f;
	
};
