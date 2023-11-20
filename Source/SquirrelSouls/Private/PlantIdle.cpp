// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantIdle.h"
#include "StationaryPlantClass.h"

void UPlantIdle::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->shouldTrack = false;
}

void UPlantIdle::OnExitState()
{
	Super::OnExitState();
}

void UPlantIdle::TickState()
{
}

void UPlantIdle::Damaged(float damage)
{
	Super::Damaged(damage);
	

}
