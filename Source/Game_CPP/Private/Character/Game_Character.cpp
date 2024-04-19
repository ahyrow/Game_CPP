// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Game_Character.h"

#include "Actors/Game_Bullet.h"
#include "Actors/Game_EnemySpawnPoint.h"
#include "Camera/CameraComponent.h"
#include "Character/Game_Enemy.h"
#include "Components/Game_AbilitySystemComponent.h"
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

	//创建技能系统组件
	AbilitySystemComponent=CreateDefaultSubobject<UGame_AbilitySystemComponent>(TEXT("PlayerAbilityComp"));
}

void AGame_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdatePlayerRotationToMouse();
}

void AGame_Character::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle_SpawnSkill;
	FTimerHandle GameTimeTimerHanld;
	
	EnemySpawnPoint =GetWorld()->SpawnActor<AGame_EnemySpawnPoint>(AGame_EnemySpawnPoint::StaticClass(), GetActorLocation(), FRotator::ZeroRotator);
	GetWorld()->GetTimerManager().SetTimer(GameTimeTimerHanld, this, &AGame_Character::Timekeeping,  1, true);

	
	for(auto Ability : AbilitySystemComponent->AbilityDatas)
	{
        if(Ability.bUnlocked)
        {
        	
        	GetWorld()->GetTimerManager().SetTimer(TimerHandle_SpawnSkill, this, &AGame_Character::BaseSKill,  SpawnTime, true);
        }
		
	}
	
}

void AGame_Character::UpdatePlayerRotationToMouse()
{

	AGame_PlayerController* PC = Cast<AGame_PlayerController>(GetController());
	if(!PC) return;

	//获得PlayerLocation
  	FVector ActorLocation = GetActorLocation();
   
	UKismetMathLibrary::BreakVector(ActorLocation,ActorLocation.X,ActorLocation.Y,ActorLocation.Z=0);

	FVector StartLocation = UKismetMathLibrary::MakeVector(ActorLocation.X,ActorLocation.Y,ActorLocation.Z=0);

	//UE_LOG(LogTemp, Log, TEXT("Player Location: %s"), *StartLocation.ToString());
    
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
		
	}
   
	PlayerDie();

	
}

void AGame_Character::PlayerDie()
{

	
	
}

void AGame_Character::BaseSKill()
{

	    FVector SpawnPoint = GetActorLocation()+FVector(30,0,0);
        FRotator Rotator = GetActorRotation();

	    AGame_Bullet* Game_Bullet = GetWorld()->SpawnActor<AGame_Bullet>(AGame_Bullet::StaticClass(),SpawnPoint,Rotator);
     if(Game_Bullet )
     {

     	Game_Bullet->SetDamage(AbilitySystemComponent->AbilityDatas[0].BaseDamage);
     }
	   
	         
}

void AGame_Character:: PlayerEXP()
{
	CurrentExp = CurrentExp+EnemiesExp;
	if(CurrentExp>MaxExp)
	{
		CurrentExp = 0;
		Level++;
		SkillPoint++;
	}
}

void AGame_Character::Timekeeping()
{
	
	Second++;
	if(Second>=60)
	{
		Minute++;
		Second=0;
	}
    if(Minute==1&&Second<60)
    {
    	EnemySpawnPoint->NewType=E_EnemyType::SmallEnemy;
    }
	else if(Minute==2&&Second<60)
	{
		EnemySpawnPoint->NewType=E_EnemyType::MiddleEnemy;
	}
	else if(Minute==3&&Second<60)
	{
		EnemySpawnPoint->NewType=E_EnemyType::BigEnemy;
	}
    
	
}

