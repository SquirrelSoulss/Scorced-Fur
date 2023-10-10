// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantStateBase.h"
#include "PlantStateBase.h"
#include "MyPlantStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSTATEMACHINE_API UMyPlantStateBase : public UPlantStateBase
{
	GENERATED_BODY()
	
	public:
	
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState()override;
	virtual void TickState()override;
};
