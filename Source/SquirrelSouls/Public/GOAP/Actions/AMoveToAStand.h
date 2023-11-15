// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Actions/GOAPAction.h"
#include "AMoveToAStand.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UAMoveToAStand : public UGOAPAction
{
	GENERATED_BODY()

	virtual bool Perform() override;
	virtual bool IsDone() override;
};
