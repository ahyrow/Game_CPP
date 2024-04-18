// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Game_AbilitySystemComponent.h"

// Sets default values for this component's properties
UGame_AbilitySystemComponent::UGame_AbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	/*BaseAbilityData.AbilityID = 0;
	BaseAbilityData.AbilityName= "基础技能";
	BaseAbilityData.BaseDamage=5;
	BaseAbilityData.bUnlocked=true;*/
}


void UGame_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

}


