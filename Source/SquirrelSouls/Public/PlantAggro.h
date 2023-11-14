// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantBaseState.h"
#include "PlantAggro.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UPlantAggro : public UPlantBaseState
{
	GENERATED_BODY()
public:



public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;

	void RangedAttack();
};
