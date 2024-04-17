// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/Game_AbilitySystemComponent.h"

// Sets default values for this component's properties
UGame_AbilitySystemComponent::UGame_AbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGame_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGame_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

bool UGame_AbilitySystemComponent::IsAbilityUnlocked(const FAbilityData& Ability) const
{
   
	 return Ability.bUnlocked;
}

void UGame_AbilitySystemComponent::ActivateAbility(const FAbilityData& Ability)
{
	UE_LOG(LogTemp, Log, TEXT("Activating Ability: %s"), *Ability.AbilityName);
}

