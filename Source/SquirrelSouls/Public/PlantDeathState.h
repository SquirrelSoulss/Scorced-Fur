// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantBaseState.h"
#include "PlantDeathState.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UPlantDeathState : public UPlantBaseState
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
