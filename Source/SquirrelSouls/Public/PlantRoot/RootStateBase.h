// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RootClass.h"
#include "CoreMinimal.h"
#include "StateBase.h"
#include "RootStateBase.generated.h"

/**
 *
 */
UCLASS()
class SQUIRRELSOULS_API URootStateBase : public UStateBase
{
	GENERATED_BODY()


public:
	
	UPROPERTY()
	ARootClass* RootRef = nullptr;

	UPROPERTY()
	AActor* PlayerRef = nullptr;

	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
