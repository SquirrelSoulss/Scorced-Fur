// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <GOAP/Actions/GOAPAction.h>
#include "GOAPNode.generated.h"


/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UGOAPNode : public UObject
{
	GENERATED_BODY()
public:
	UGOAPNode* parent;
	float runningCost;
	TMap<FString, bool> state;
	UGOAPAction* action;
	void InitializeFields(UGOAPNode* inParent, float inRunningcost, TMap<FString, bool> inState, UGOAPAction* inAction);

	UGOAPNode() = default;
};
