// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingSuspiciousState.h"
//in damage state put should traxck to true and set track speed much higher
void UMovingSuspiciousState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->shouldTrack = true;
	//youve seen the player decide on wether you should leap backwards, strafe or run towards player
	//leap backwards if player is close and presses the attack button (do this every thrid or so)
	//50/50 between strafe and lunge attack, if player gets close attack
}

void UMovingSuspiciousState::OnExitState()
{
	Super::OnExitState();
}

void UMovingSuspiciousState::TickState()
{
	Super::TickState();
	//shoot lasers in two directions in order to se if you see the player
	for (int i = 0; i < 10; i++) 
	{
		/*TArray<FVector> pointsOfINterest;
		pointsOfINterest.Push(FVector(0, 0, 0));*/
		
	}
}

void UMovingSuspiciousState::Damaged(float damage)
{
	Super::Damaged(damage);
}
