// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "EntClass.h"
#include "EntStateBase.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEntStateBase : public UStateBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	AActor* playerRef = nullptr;

	UPROPERTY()
	AEntClass* EntRef = nullptr;

	UPROPERTY(EditDefaultsOnly, Category = "Attack types")
	TMap<FString, int> AttackTypes;

public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
