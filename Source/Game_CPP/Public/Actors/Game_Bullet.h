// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game_Bullet.generated.h"

class UProjectileMovementComponent;
class USphereComponent;
class UStaticMeshComponent;
UCLASS()
class GAME_CPP_API AGame_Bullet : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AGame_Bullet();
virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Bullet;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> PMC;

	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);

	float ToEnemyBaseDamage = 10.f;
};
