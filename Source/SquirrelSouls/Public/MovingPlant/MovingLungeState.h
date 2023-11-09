// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "MovingLungeState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UMovingLungeState : public UMovingPlantBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void LaunchTowardsPlayer();
	void ChangeToStrafe();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector launchHeight = FVector(0, 0, 500);
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float launchDistance = 1000;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float gravityDuringJump = 3.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float transitionTime = 1.5f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float transitionToForwardLaunch = 0.15f;
	float originalGravityscale = 1.f;
};
