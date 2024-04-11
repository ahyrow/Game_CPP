// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Game_Enemy.h"

#include "AIController.h"
#include "AIHelpers.h"
#include "Character/Game_Character.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Tasks/AITask_MoveTo.h"

// Sets default values
AGame_Enemy::AGame_Enemy()
{
	EnemyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyStaticMesh"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("EnemyStaticMesh"));
	EnemyLifeWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyStaticMesh"));

	
	Sphere->SetupAttachment(EnemyStaticMesh);
}

// Called when the game starts or when spawned
void AGame_Enemy::BeginPlay()
{
	Super::BeginPlay();

	
	AAIController* AIController= Cast<AAIController>(GetController());
	if(AIController)
	{  
      
       	
		AActor* Player=UGameplayStatics::GetPlayerCharacter(GetWorld(),0);

		//FVector TargetLocation = Player->GetActorLocation();
		float Radius =100.f;
		bool bStopOnOverlap=true;
		AIController->MoveToActor(Player,Radius,bStopOnOverlap);
	}
}


