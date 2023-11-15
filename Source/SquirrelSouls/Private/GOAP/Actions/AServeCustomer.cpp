// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/AServeCustomer.h"



bool UAServeCustomer::Perform()
{
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Serve customer!"));
	//Play idle animation set the world state to serving customer or something
	return false;
}

bool UAServeCustomer::IsDone()
{
	
	return true; //change to false
}
