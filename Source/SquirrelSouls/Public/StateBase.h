// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StateBase.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SQUIRRELSOULS_API UStateBase : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanTickState = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanRepeatState = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateDisplayName;



	UPROPERTY(BlueprintReadOnly)
	AActor* enemy = nullptr;
public:
	virtual void OnEnterState(AActor* stateOwner);
	virtual void OnExitState();

	virtual void TickState();
	virtual void PlayerOverlapping();
	virtual void Damaged(float damage);
};
