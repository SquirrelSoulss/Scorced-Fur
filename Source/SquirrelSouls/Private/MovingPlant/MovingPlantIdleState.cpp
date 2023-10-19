// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingPlantIdleState.h"

void UMovingPlantIdleState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisMovingPlant->GetPatrolPoint();

	aiController->MoveToLocation(thisMovingPlant->randomPoint);
	//get a random position within bounds
	//start a moveto 
}

void UMovingPlantIdleState::OnExitState()
{
	Super::OnExitState();
	//Cancel moveto
}

void UMovingPlantIdleState::TickState()
{
	Super::TickState();
}

void UMovingPlantIdleState::PlayerOverlapping()
{
	Super::PlayerOverlapping();
	//switch to suspicious
}
