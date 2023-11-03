// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "StateBase.h"
#include "StationaryPlantClass.h"
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
	AStationaryPlantClass* thisPlant = nullptr;
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;
	void FixRotation(FVector actorLocation, FVector targetLocation);
	
};
