// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntTransitionP2.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEntTransitionP2 : public UEntStateBase
{
	GENERATED_BODY()
	
	UPROPERTY()
	bool HasInitialized = false;

	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;

	void InitializeP2();
};
