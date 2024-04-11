// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_Bullet.h"

#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AGame_Bullet::AGame_Bullet()
{
	Bullet= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	PMC= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PMC"));

	Sphere->SetupAttachment(Bullet);
	
}



