// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/AServeCustomer.h"
#include "GOAP/Labourer.h"
#include "GOAP/Merchant.h" 


bool UAServeCustomer::Perform(float DeltaTime)
{
	if (!runAgain)
		return true;
	runAgain = false;
	AMerchant* a = Cast<AMerchant>(myAgent);
	a->isIdlyWaiting = true;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Serve customer!"));
	//Play idle animation set the world state to serving customer or something
	return false;
}

bool UAServeCustomer::IsDone()
{
	
	return true; //change to false
}
