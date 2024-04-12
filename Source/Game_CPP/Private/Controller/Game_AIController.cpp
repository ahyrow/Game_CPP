// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/Game_AIController.h"
#include "Kismet/GameplayStatics.h"

AGame_AIController::AGame_AIController()
{
	AcceptanceRadius=30.f;
}

void AGame_AIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	AIMovePlayer();
}

void AGame_AIController::BeginPlay()
{
	Super::BeginPlay();
	
}

void AGame_AIController::AIMovePlayer()
{
	if(bIsMove)
	{
		if(APawn* MyPawn=UGameplayStatics::GetPlayerPawn(GetWorld(),0))
		
		{
	 	
			MoveToActor(MyPawn,AcceptanceRadius);
		};

	};
	
	
}

void AGame_AIController::WaitTime(float Seconds)
{
    if(Seconds>0.f)
    {
    	bIsMove=false;
    	
    	//*根据传入的秒数停止移动*/
	    StopMovement();

    	//*设置定时器*/
    	FTimerHandle TimerHandle;
    	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AGame_AIController::OnWaitFinished,Seconds , false);

    	UE_LOG(LogTemp,Log,TEXT("%f"),Seconds);
    };

	
	
}

void AGame_AIController::OnWaitFinished()
{

	bIsMove = true;
	
}
