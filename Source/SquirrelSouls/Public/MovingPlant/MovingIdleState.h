// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingIdleState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingIdleState : public UMovingPlantBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	UFUNCTION()
	void IsReachablePoint(FVector position, int32 depth);
	UFUNCTION()
	void StartAiMoveTo();
};
