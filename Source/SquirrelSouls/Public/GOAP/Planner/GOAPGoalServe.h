// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Planner/GOAPGoal.h"
#include "GOAPGoalServe.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UGOAPGoalServe : public UGOAPGoal
{
	GENERATED_BODY()
public:
	virtual float GetPriority() override;
	TMap<FString, bool> statesMap;
};
