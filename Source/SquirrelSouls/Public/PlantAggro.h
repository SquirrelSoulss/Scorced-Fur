// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "PlantAggro.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UPlantAggro : public UStateBase
{
	GENERATED_BODY()
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
