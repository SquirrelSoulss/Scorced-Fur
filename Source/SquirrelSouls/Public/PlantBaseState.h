// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "EnemyBaseClass.h"
#include "PlantBaseState.generated.h"


/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UPlantBaseState : public UStateBase
{
	GENERATED_BODY()
public:
	UPROPERTY()
	AActor* mainCharacter = nullptr;

	UPROPERTY()
	AEnemyBaseClass* thisPlant = nullptr;
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;
};
