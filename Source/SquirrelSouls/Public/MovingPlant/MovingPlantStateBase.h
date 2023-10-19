// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlantClass.h"
#include "AIController.h"
#include "StateBase.h"
#include "MovingPlantStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingPlantStateBase : public UStateBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void PlayerOverlapping() override;
protected:
	AAIController* aiController;
	AMovingPlantClass* thisMovingPlant;
};
