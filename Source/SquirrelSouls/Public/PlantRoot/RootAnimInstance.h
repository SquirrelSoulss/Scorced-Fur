// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "RootAnimInstance.generated.h"

/**
 * 
 */
class ARootClass;

UCLASS()
class SQUIRRELSOULS_API URootAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

public:
	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	ARootClass* RootRef = nullptr;

	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	bool IsNormalAttack = false;

	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	bool IsSwipeAttack = false;

	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	bool TookDamage = false;

	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	bool IsParried = false;

	UPROPERTY(BlueprintReadWrite, Category = "StateTriggers")
	bool IsDead = false;
};
