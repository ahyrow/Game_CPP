// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller/Game_PlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Input/Game_IA_PlayerMove.h"
#include "Input/Game_IMC.h"


AGame_PlayerController::AGame_PlayerController()
{
	
	/*GameContext= NewObject<UGame_IMC>();
	PlayerMoveAction =NewObject<UGame_IA_PlayerMove>();*/
	
}

void AGame_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(GameContext);
	UEnhancedInputLocalPlayerSubsystem* LocalPlayerSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	// check(LocalPlayerSubsystem)
	if(LocalPlayerSubsystem)
	{
		LocalPlayerSubsystem->AddMappingContext(GameContext,0);	
	};

	bShowMouseCursor = false;
	FInputModeGameOnly InputData;
	SetInputMode(InputData);
}

void AGame_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent =CastChecked<UEnhancedInputComponent>(InputComponent); 
    //UGame_EnhancedInputComponent* Game_EnhancedInputComponent = Cast<UGame_EnhancedInputComponent>(EnhancedInputComponent);
	
	EnhancedInputComponent->BindAction(PlayerMoveAction,ETriggerEvent::Triggered,this,&AGame_PlayerController::PlayerMove);
}

void AGame_PlayerController::PlayerMove(const  FInputActionValue& InputActinValue)
{

	const 	FVector2D InputVector2D = InputActinValue.Get<FVector2D>();
    const 	FRotator Rotator = GetControlRotation();

    const  FRotator YawRotation(0,Rotator.Yaw,0);

    const 	FVector ForwordDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const 	FVector RightDir = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if(APawn* MyPlayer = GetPawn<APawn>())
	{
		MyPlayer->AddMovementInput(ForwordDir,InputVector2D.Y);
		MyPlayer->AddMovementInput(RightDir,InputVector2D.X);
	}
	
}
