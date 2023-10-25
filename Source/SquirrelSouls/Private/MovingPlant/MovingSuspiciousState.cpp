// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingSuspiciousState.h"

void UMovingSuspiciousState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	//youve seen the player decide on wether you should leap backwards, strafe or run towards player
	//leap backwards if player is close and presses the attack button (do this every thrid or so)
	//50/50 between strafe and attack, if player gets close attack
}

void UMovingSuspiciousState::OnExitState()
{
	Super::OnExitState();
}

void UMovingSuspiciousState::TickState()
{
	Super::TickState();
}

void UMovingSuspiciousState::Damaged(float damage)
{
	Super::Damaged(damage);
}
