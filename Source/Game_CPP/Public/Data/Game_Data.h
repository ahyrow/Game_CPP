// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "Engine/Texture2D.h"
#include "Game_Data.generated.h"

/*技能数据*/
USTRUCT(BlueprintType)
struct FAbilityData
{
   GENERATED_BODY()

	//技能ID
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	int32 AbilityID;
	//技能名字
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	FString AbilityName;
	//技能描述
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	FString Description;
	//基础伤害
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	float BaseDamage;
	//是否解锁
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	bool bUnlocked;
	//技能图片
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Ability")
	UTexture2D* AbilityIcon;
};
  /*
   * 技能升级效果
   */

USTRUCT(BlueprintType)
struct  FAbilityUpgrade
{
	GENERATED_BODY()

    //增加伤害
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Upgrade")
	float AddDamage;
	//增加范围
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Upgrade")
	float AddEffectRange;
};


/**
 * 
 */

class GAME_CPP_API Game_Data
{
public:
	Game_Data();
	~Game_Data();
};
