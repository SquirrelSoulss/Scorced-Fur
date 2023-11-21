// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Actions/GOAPAction.h"
#include "EmptyAction.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEmptyAction : public UGOAPAction
{
	GENERATED_BODY()
	virtual bool Perform(float DeltaTime) override;
	virtual bool IsDone() override;
	bool runAgain = true;
};
