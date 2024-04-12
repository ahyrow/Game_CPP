// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Game_Character.h"

#include "Actors/Game_Bullet.h"
#include "Camera/CameraComponent.h"
#include "Controller/Game_PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/EngineTypes.h"


AGame_Character::AGame_Character()
{
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	WirteBoxPlayer=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->bUsePawnControlRotation = true;
	SpringArmComponent->bInheritYaw=false;
	SpringArmComponent->bInheritPitch=false;
	SpringArmComponent->bInheritRoll=false;

	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->SetRelativeRotation(FRotator(-60,0,0));
	SpringArmComponent->bDoCollisionTest = false;

	PlayerCurrentHealth=10.f;
	PlayerMaxHealth=100.f;
}

void AGame_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdatePlayerRotationToMouse();
}

void AGame_Character::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_SpawnSkill, this, &AGame_Character::BaseSKill,  SpawnTime, true);
}

void AGame_Character::UpdatePlayerRotationToMouse()
{

	AGame_PlayerController* PC = Cast<AGame_PlayerController>(GetController());
	if(!PC) return;

	//获得PlayerLocation
  	FVector ActorLocation = GetActorLocation();
   
	UKismetMathLibrary::BreakVector(ActorLocation,ActorLocation.X,ActorLocation.Y,ActorLocation.Z=0);

	FVector StartLocation = UKismetMathLibrary::MakeVector(ActorLocation.X,ActorLocation.Y,ActorLocation.Z=0);

	UE_LOG(LogTemp, Log, TEXT("Player Location: %s"), *StartLocation.ToString());
    
	FHitResult HitResult;
	bool bIsHit = PC->GetHitResultUnderCursorByChannel(UEngineTypes::ConvertToTraceType(ECollisionChannel::ECC_Visibility),true,HitResult);
    if(bIsHit)
   {
    	
	    FVector HitResultLocation = HitResult.Location;
    
        UKismetMathLibrary::BreakVector(HitResultLocation,HitResultLocation.X,HitResultLocation.Y,HitResultLocation.Z=0);

    	FVector EndLocation = UKismetMathLibrary::MakeVector(HitResultLocation.X,HitResultLocation.Y,0);
    	
    	SetActorRotation(UKismetMathLibrary::FindLookAtRotation(StartLocation, EndLocation));

    	
    	WirteBoxPlayer->SetWorldLocation(EndLocation);
    }


	
	
}

void AGame_Character::HealthLoss(float Damage)
{

	if(PlayerCurrentHealth>0)
	{
		PlayerCurrentHealth=PlayerCurrentHealth-Damage;
		UE_LOG(LogTemp,Log,TEXT("PlayerCurrentHealth: %f"),PlayerCurrentHealth);
	}
   
	PlayerDie();

	
}

void AGame_Character::PlayerDie()
{

	UE_LOG(LogTemp,Log,TEXT("PlayerCurrentHealth: %f,玩家已经死亡"),PlayerCurrentHealth)
	
}

void AGame_Character::BaseSKill()
{

	if(BulletClass!=nullptr)
	{

		FVector SpawnPoint = GetActorLocation()+FVector(30,0,0);
        FRotator Rotator = GetActorRotation();

		GetWorld()->SpawnActor<AActor>(BulletClass,SpawnPoint,Rotator);
		
	}
}

