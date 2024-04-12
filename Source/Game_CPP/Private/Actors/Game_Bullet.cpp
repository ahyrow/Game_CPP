// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_Bullet.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AGame_Bullet::AGame_Bullet()
{

    InitialLifeSpan = 5.f;
	
	Bullet= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Bullet"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	PMC= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PMC"));

	Bullet->SetupAttachment(RootComponent);
	Sphere->SetupAttachment(Bullet);


	PMC->InitialSpeed=100.f;
	PMC->MaxSpeed=1000.f;
	//设置无重力
	PMC->ProjectileGravityScale = 0.f;
	
	
}



