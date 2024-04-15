// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_Bullet.h"

#include "Character/Game_Enemy.h"
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
	Sphere->SetSphereRadius(210.f);
	
	Sphere->BodyInstance.SetCollisionProfileName(TEXT("Custom"));
	Sphere->BodyInstance.SetObjectType(ECC_WorldDynamic);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Sphere->SetCollisionObjectType(ECC_WorldDynamic);
	Sphere->SetCollisionResponseToAllChannels(ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Overlap);

	PMC->InitialSpeed=100.f;
	PMC->MaxSpeed=1000.f;
	//设置无重力
	PMC->ProjectileGravityScale = 0.f;
	
	
}

void AGame_Bullet::BeginPlay()
{
	Super::BeginPlay();
	Sphere->OnComponentBeginOverlap.AddDynamic(this,&AGame_Bullet::OnBeginOverlap);
}

void AGame_Bullet::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
                                  UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if( AGame_Enemy* Enemy = Cast<AGame_Enemy>(OtherActor))
    {
    	   Destroy();
           Enemy->UpDateEnemyHealth(ToEnemyBaseDamage);
    	
    }
	
   
	
}



