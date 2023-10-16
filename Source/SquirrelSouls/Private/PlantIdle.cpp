// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantIdle.h"
#include "StationaryPlantClass.h"

void UPlantIdle::OnEnterState(AActor* stateOwner)
{
	thisPlant = Cast<AStationaryPlantClass>(stateOwner);
	if (thisPlant != nullptr) 
	{
		thisPlant->sensesPlayer = false;
	}
}

void UPlantIdle::OnExitState()
{
}

void UPlantIdle::TickState()
{
}
