// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Game_Enemy.h"


#include "Character/Game_Character.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Controller/Game_AIController.h"
#include "GameFramework/CharacterMovementComponent.h"



// Sets default values
AGame_Enemy::AGame_Enemy()
{
	EnemyStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EnemyStaticMesh"));
	Sphere= CreateDefaultSubobject<USphereComponent>(TEXT("SpherComp"));
	EnemyStaticMesh->SetupAttachment(RootComponent);

	Sphere->SetSphereRadius(80.f);
	//设置碰撞
	EnemyStaticMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Sphere->BodyInstance.SetCollisionProfileName(TEXT("Custom"));
	Sphere->BodyInstance.SetObjectType(ECC_WorldDynamic);
	Sphere->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Sphere->SetCollisionObjectType(ECC_WorldDynamic);
	Sphere->SetCollisionResponseToAllChannels(ECR_Overlap);
	Sphere->SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Ignore);


	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Custom"));
	GetCapsuleComponent()->SetCollisionObjectType(ECC_WorldDynamic);
	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetCapsuleComponent()->SetCollisionResponseToAllChannels(ECR_Block);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_GameTraceChannel2,ECR_Ignore);
	GetCapsuleComponent()->SetCollisionResponseToChannel(ECC_Pawn,ECR_Block);
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Script/Engine.StaticMesh'/Game/Cone_Merge_Merge_F20428AC.Cone_Merge_Merge_F20428AC'"));

	if(MeshAsset.Succeeded())
	{
		EnemyStaticMesh->SetStaticMesh(MeshAsset.Object);
	}
	//EnemyLifeWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("EnemyStaticMesh"));
	AIControllerClass = AGame_AIController::StaticClass();

	Sphere->SetupAttachment(EnemyStaticMesh);
	GetCharacterMovement()->MaxWalkSpeed=EnemyMoveSpeed;
	
}

// Called when the game starts or when spawned
void AGame_Enemy::BeginPlay()
{
	 Super::BeginPlay();
	 SetEnemyInfo(E_EnemyType::SmallEnemy);
	
     Sphere->OnComponentBeginOverlap.AddDynamic(this,&AGame_Enemy::OnBeginOverlap);
}

void AGame_Enemy::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	
	
}

void AGame_Enemy::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult)
{


    // UE_LOG(LogTemp,Log,TEXT("%s"),*OtherActor->GetName());
	
	AGame_Character* PlayrCharacter = Cast<AGame_Character>(OtherActor);

	if(PlayrCharacter)
	{
		
		if(  AGame_AIController* AIController =  GetWorld()->SpawnActor<AGame_AIController>(AIControllerClass) )
		{
			AIController->Possess(this);
			AIController->WaitTime(5.f);
		}

		PlayrCharacter->HealthLoss(DamageToPlayer);
		
	}
	
	
}

 void AGame_Enemy::SetEnemyInfo (E_EnemyType _EnemyType)
{
	
	switch (_EnemyType)
	{
	case  E_EnemyType::SmallEnemy:
		EnemyInfo = FEnemyInfo{20,20,5,13,1};

		break;
	
	case  E_EnemyType::MiddleEnemy:
		EnemyInfo = FEnemyInfo{50,50,15,200,0.8};

		break;
	case  E_EnemyType::BigEnemy:
		EnemyInfo = FEnemyInfo{100,100,20,280,0.6};

		
		break;
	}
	
}

void AGame_Enemy::SetEnemyType(int32 GameTime)
{
	/*switch (GameTime)
	{
	case 1 : 
     
		
		
	}
	*/
	 
    

	
}

void AGame_Enemy::UpDateEnemyHealth(float Damage)
{
	if ( EnemyInfo.CurrentHealth>0)
	{
		EnemyInfo.CurrentHealth = EnemyInfo.CurrentHealth-Damage;
		UE_LOG(LogTemp,Log,TEXT("EnemyCurrentHealth: %f"),EnemyInfo.CurrentHealth)
	}
	else
	{
		Destroy();
		UE_LOG(LogTemp,Log,TEXT("Enemy已经死亡"))
		
	}
  
}








