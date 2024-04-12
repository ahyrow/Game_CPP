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


	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Bullet;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> Sphere;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UProjectileMovementComponent> PMC;



	
};
