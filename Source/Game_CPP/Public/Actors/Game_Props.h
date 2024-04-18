// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Game_Props.generated.h"

UENUM()
enum  class E_PropType : uint8
{
     
     HealthPotion,
	 SpeedPotion
	
};



class UStaticMeshComponent;
class USphereComponent;
UCLASS()
class GAME_CPP_API AGame_Props : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGame_Props();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


public:
    E_PropType PropType;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UStaticMeshComponent> Prop;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> SphereComponent;

	
	UFUNCTION()
	void OnBeginOverlap(UPrimitiveComponent* OnComponentBeginOverlap,
		AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,const FHitResult& SweepResult);


    void SetSpawnPropType(E_PropType SpwanPotionType);
	
};
