// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Data/Game_Data.h"
#include "Game_AbilitySystemComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GAME_CPP_API UGame_AbilitySystemComponent : public UActorComponent
{
	
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGame_AbilitySystemComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:
	/*
	 * 技能管理
	 */
    
	UPROPERTY(EditAnywhere)
    TArray<FAbilityData> AbilityDatas;
	
	

	
	
};
