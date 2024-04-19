// Fill out your copyright notice in the Description page of Project Settings.


#include "Actors/Game_Props.h"
#include "Character/Game_Character.h"
#include "Components/SphereComponent.h"


// Sets default values
AGame_Props::AGame_Props()
{
	PrimaryActorTick.bCanEverTick = true;
	
	Prop= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PropComp"));
	SphereComponent= CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	
	Prop->SetupAttachment(RootComponent);
	SphereComponent->SetupAttachment(Prop);
	RootComponent = Prop;



 	/*
	 * 碰撞
	 */
	SphereComponent->BodyInstance.SetCollisionProfileName(TEXT("Custom"));
	SphereComponent->BodyInstance.SetObjectType(ECC_WorldDynamic);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	SphereComponent->SetCollisionObjectType(ECC_WorldDynamic);
	SphereComponent->SetCollisionResponseToAllChannels(ECR_Overlap);
	SphereComponent->SetCollisionResponseToChannel(ECC_Pawn,ECR_Overlap);
    
}

// Called when the game starts or when spawned
void AGame_Props::BeginPlay()
{
	
Super::BeginPlay();
	
}

// Called every frame
void AGame_Props::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGame_Props::OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
     //玩家一碰到之后
	AGame_Character* PlayrCharacter = Cast<AGame_Character>(OtherActor);
	if(PlayrCharacter)
	{
		//根据类型选择加生命加速度
		
	}
	
	
}

void AGame_Props::SetSpawnPropType(E_PropType SpwanPotionType)
{

	PropType = SpwanPotionType;

	if(PropType==E_PropType::HealthPotion)
	{
	   UE_LOG(LogTemp,Log,TEXT("掉落生命值药水"))
		
	}  
	else if(PropType==E_PropType::SpeedPotion)
	{
		
		UE_LOG(LogTemp,Log,TEXT("掉落速度药水"))
	}
	
}


