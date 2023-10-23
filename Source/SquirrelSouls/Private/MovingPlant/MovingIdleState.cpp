// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingIdleState.h"

void UMovingIdleState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
}

void UMovingIdleState::OnExitState()
{
}

void UMovingIdleState::TickState()
{
}

void UMovingIdleState::Damaged(float damage)
{
	Super::Damaged(damage * 1.5f); // idle state 
}
