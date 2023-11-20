// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantBaseState.h"
#include "StationaryPlantHurt.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UStationaryPlantHurt : public UPlantBaseState
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
	virtual void Damaged(float damage) override;
	void SwitchToDecideState();
	void BoolChange();
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	float timeToTransition = 1.f;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	UAnimMontage* animMontage;
};
