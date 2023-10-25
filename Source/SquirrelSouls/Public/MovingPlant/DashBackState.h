// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MovingPlant/MovingPlantBase.h"
#include "DashBackState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UDashBackState : public UMovingPlantBase
{
	GENERATED_BODY()
	FTimerHandle handle;
public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FVector launchHeight = FVector(0, 0, 200);
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float launchDistance = 1000;
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void LaunchCharacterBack();
};
