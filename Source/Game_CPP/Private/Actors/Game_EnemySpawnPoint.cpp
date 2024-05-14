// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_EnemySpawnPoint.h"
#include "Controller/Game_AIController.h"
#include "Kismet/KismetMathLibrary.h"

class AGame_AIController;
// Sets default values
AGame_EnemySpawnPoint::AGame_EnemySpawnPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGame_EnemySpawnPoint::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AGame_EnemySpawnPoint::SpawnEnemy,SpawnSpeed,true);

	
}  

// Called every frame
void AGame_EnemySpawnPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGame_EnemySpawnPoint::SpawnEnemy()
{
	int32 RandomInt = UKismetMathLibrary::RandomIntegerInRange(1,4);
	float Point= UKismetMathLibrary::RandomIntegerInRange(-2400,2400);
	
	switch (RandomInt)
	{
	case 1 :
		{
			FVector SpawnPoint1 = UKismetMathLibrary::MakeVector(Point,2400,100);
			SpawnAIPC(SpawnPoint1);
			break;
		}
	case 2:
		{
			FVector SpawnPoint2 = UKismetMathLibrary::MakeVector(2400,Point,100);
			SpawnAIPC(SpawnPoint2);
			break;
		}
	
	case 3:
		{
			
			FVector SpawnPoint3 = UKismetMathLibrary::MakeVector(Point,-2400,100);
			SpawnAIPC(SpawnPoint3);
			break;
		}
		
		 
		
	case 4:
		{
			FVector SpawnPoint4 = UKismetMathLibrary::MakeVector(Point,-2400,100);
			SpawnAIPC(SpawnPoint4);
			break;
		}
	
	}


	

	
} 

void AGame_EnemySpawnPoint::SpawnAIPC(FVector NewSpawnPoint)
{
	
	AGame_Enemy* Enemy = GetWorld()->SpawnActor<AGame_Enemy>(AGame_Enemy::StaticClass(),  NewSpawnPoint, FRotator::ZeroRotator);
	AGame_AIController* AIController = GetWorld()->SpawnActor<AGame_AIController>(Enemy->AIControllerClass,  NewSpawnPoint, FRotator::ZeroRotator);
	if (Enemy&&AIController)
	{
		E_EnemyType _NewType  =NewType;
		Enemy->SetEnemyType(_NewType);
		SpawnSpeed=Enemy->GetEnemyInfo(_NewType).SpawnFrequency;
		AIController->Possess(Enemy);
		
	}

}


