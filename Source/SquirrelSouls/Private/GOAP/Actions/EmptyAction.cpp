// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/EmptyAction.h"
#include "GOAP/Merchant.h"

bool UEmptyAction::Perform(float DeltaTime)
{
	if (!runAgain)
		return true;
	runAgain = false;
	AMerchant* a = Cast<AMerchant>(myAgent);
	a->isIdlyWaiting = false;
	return false;
}

bool UEmptyAction::IsDone()
{
	return false;
}
