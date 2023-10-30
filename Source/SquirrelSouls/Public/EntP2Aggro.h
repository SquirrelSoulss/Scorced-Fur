// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntAggro.h"
#include "EntP2Aggro.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEntP2Aggro : public UEntAggro
{
	GENERATED_BODY()
	
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;

	UFUNCTION()
	void AddAvailableAttacks();
};
