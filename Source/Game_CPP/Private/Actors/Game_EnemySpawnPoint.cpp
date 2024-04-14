// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_EnemySpawnPoint.h"

#include "Character/Game_Enemy.h"
#include "Kismet/KismetMathLibrary.h"

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

	/*FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle,this,&AGame_EnemySpawnPoint::SpawnEnemy,1,true);*/
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
			
			SpawnPoint = UKismetMathLibrary::MakeVector(Point,2400,100);
			if (UWorld* World = GetWorld())
			{
				AGame_Enemy* Enemy = World->SpawnActor<AGame_Enemy>(AGame_Enemy::StaticClass(), SpawnPoint, FRotator::ZeroRotator);
		        
			};
			break;
		}
	case 2:
		{
			SpawnPoint = UKismetMathLibrary::MakeVector(2400,Point,100);
			if (UWorld* World = GetWorld())
			{
					AGame_Enemy* Enemy= World->SpawnActor<AGame_Enemy>(AGame_Enemy::StaticClass(), SpawnPoint, FRotator::ZeroRotator);
		
			};
			
			
			break;
		}
	
	case 3:
		{
			
			SpawnPoint = UKismetMathLibrary::MakeVector(Point,-2400,100);
			if (UWorld* World = GetWorld())
			{
				
				AGame_Enemy* Enemy= World->SpawnActor<AGame_Enemy>(AGame_Enemy::StaticClass(), SpawnPoint, FRotator::ZeroRotator);
			};
			break;
		}
		
		 
		
	case 4:
		{
			
			SpawnPoint = UKismetMathLibrary::MakeVector(Point,-2400,100);
			if (UWorld* World = GetWorld())
			{
			 AGame_Enemy* Enemy = World->SpawnActor<AGame_Enemy>(AGame_Enemy::StaticClass(), SpawnPoint, FRotator::ZeroRotator);
		
			};
			break;
		}
	
	}


	

	
}


