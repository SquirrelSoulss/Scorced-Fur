// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantBaseState.h"
#include "PlantRangedAttackState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UPlantRangedAttackState : public UPlantBaseState
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
