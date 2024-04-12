// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Game_Enemy.h"

#include "AIController.h"
#include "Character/Game_Character.h"
#include "Components/SphereComponent.h"
#include "Controller/Game_AIController.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values
AGame_Enemy::AGame_Enemy()
{
	EnemyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyStaticMesh"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("SpherComp"));
	EnemyStaticMesh->SetupAttachment(RootComponent);
	//EnemyLifeWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyStaticMesh"));

	
	Sphere->SetupAttachment(EnemyStaticMesh);

	GetCharacterMovement()->MaxWalkSpeed=EnemyMoveSpeed;
}

// Called when the game starts or when spawned
void AGame_Enemy::BeginPlay()
{
	 Super::BeginPlay();

     Sphere->OnComponentBeginOverlap.AddDynamic(this,&AGame_Enemy::OnBeginOverlap);
}

void AGame_Enemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
}

void AGame_Enemy::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{


     UE_LOG(LogTemp,Log,TEXT("%s"),*OtherActor->GetName());
	
	AGame_Character* PlayrCharacter = Cast<AGame_Character>(OtherActor);
	if(PlayrCharacter)
	{
		if( AGame_AIController* AIController= Cast<AGame_AIController>(GetController()))
		{
			AIController->WaitTime(5.f);
		}

		PlayrCharacter->HealthLoss(DamageToPlayer);
		
	}
	
	
}





