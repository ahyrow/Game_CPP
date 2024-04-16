// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_Bullet.h"

#include "Character/Game_Enemy.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Math/TransformCalculus3D.h"

// Sets default values
AGame_Bullet::AGame_Bullet()
{
	
	Bullet= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BulletComp"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	PMC= CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("PMC"));
	
	
	Bullet->SetupAttachment(RootComponent);
	RootComponent = Bullet;
	Sphere->SetupAttachment(Bullet);
	Bullet->SetRelativeScale3D(FVector(0.5,0.5,0.5));
	Sphere->SetSphereRadius(100.f);

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Sphere_9A2EFB8B.Sphere_9A2EFB8B'"));

	if(MeshAsset.Succeeded())
	{
		Bullet->SetStaticMesh(MeshAsset.Object);
	}
	/*
	 * 碰撞
	 */
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
	
	InitialLifeSpan = 5.f;
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



