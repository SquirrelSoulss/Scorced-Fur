// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlantRoot/RootStateBase.h"
#include "RootAggro.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API URootAggro : public URootStateBase
{
	GENERATED_BODY()
	
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;
};
