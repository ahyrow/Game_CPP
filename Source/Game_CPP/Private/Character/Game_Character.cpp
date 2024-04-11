// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/Game_Character.h"
#include "Camera/CameraComponent.h"
#include "Controller/Game_PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/EngineTypes.h"


AGame_Character::AGame_Character()
{
	SpringArmComponent=CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	CameraComponent=CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));

	SpringArmComponent->SetupAttachment(RootComponent);
	CameraComponent->SetupAttachment(SpringArmComponent);

	SpringArmComponent->TargetArmLength = 800.f;
	SpringArmComponent->SetRelativeRotation(FRotator(-60,0,0));
	SpringArmComponent->bDoCollisionTest = false;
}

void AGame_Character::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UpdatePlayerRotationToMouse();
}

void AGame_Character::UpdatePlayerRotationToMouse()
{

	AGame_PlayerController* PC = Cast<AGame_PlayerController>(GetController());
	if(!PC) return;

	//获得PlayerLocation
  	FVector ActorLocation = GetActorLocation();
    FVector StartLocation(ActorLocation.X,ActorLocation.X,0);

	FHitResult HitResult;
	PC->GetHitResultUnderCursorByChannel(TraceTypeQuery1,true,HitResult);
	
	FVector EndLocation(HitResult.Location.X,HitResult.Location.Y,0);

	FRotator ActorRotation =  UKismetMathLibrary::FindLookAtRotation(StartLocation, EndLocation);
    SetActorRotation(ActorRotation);
}

