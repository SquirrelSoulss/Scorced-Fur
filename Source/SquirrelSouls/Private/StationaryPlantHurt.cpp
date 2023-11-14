// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryPlantHurt.h"
#include "StateManagerComponent.h"


void UStationaryPlantHurt::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->damaged = true;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UStationaryPlantHurt::SwitchToDecideState,timeToTransition, false);
}

void UStationaryPlantHurt::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	thisPlant->damaged = false;
}

void UStationaryPlantHurt::TickState()
{
	Super::TickState();
}

void UStationaryPlantHurt::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UStationaryPlantHurt::SwitchToDecideState()
{
	thisPlant->stateManager->SwitchStateByKey("Aggro");
}
