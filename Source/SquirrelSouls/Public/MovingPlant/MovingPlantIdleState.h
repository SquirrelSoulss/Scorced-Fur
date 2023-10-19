// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantStateBase.h"
#include "MovingPlantIdleState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingPlantIdleState : public UMovingPlantStateBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void PlayerOverlapping() override;
};
