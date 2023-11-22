// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Actions/GOAPAction.h"
#include "AServeCustomer.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UAServeCustomer : public UGOAPAction
{
	GENERATED_BODY()
public:

	virtual bool Perform(float DeltaTime) override;
	virtual bool IsDone() override;
	virtual void AbortAction() override;
	void GivePotions();
	bool givenPotions = false;
	bool runAgain = true;
};
