// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingStrafeState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingStrafeState : public UMovingPlantBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void Strafe();
	void ChangeToLeapAttack();
	int32 depth;

};
