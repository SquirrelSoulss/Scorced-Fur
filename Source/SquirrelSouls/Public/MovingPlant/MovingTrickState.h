// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingTrickState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingTrickState : public UMovingPlantBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector launchHeight = FVector(0, 0, 500);
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float launchDistance = 1000;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float launchDistanceForward = 1000;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float gravityDuringJump = 3.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float timeBetweenJumps = .3f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float timeToSwitch = .3f;
	float originalGravityscale = 1.f;
	int32 depth = 1;
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void ZigZag();
	void SwitchToAggro();
	void Forwards();
};
