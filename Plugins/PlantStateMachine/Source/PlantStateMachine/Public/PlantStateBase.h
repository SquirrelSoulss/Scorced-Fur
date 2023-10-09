// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PlantStateBase.generated.h"

/**
 * 
 */
UCLASS()
class PLANTSTATEMACHINE_API UPlantStateBase : public UObject
{
	GENERATED_BODY()

	public:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanTickState = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	bool bCanRepeatState = false;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly)
	FName StateDisplayName;

	public:
		virtual void OnEnterState(AActor* stateOwner);
		virtual void OnExitState();
		virtual void TickState();

};
