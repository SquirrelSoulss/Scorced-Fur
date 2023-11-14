// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntDeath.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEntDeath : public UEntStateBase
{
	GENERATED_BODY()
	
	virtual void OnEnterState(AActor* stateOwner) override;

};
