// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/DashBackState.h"

void UDashBackState::OnEnterState(AActor* stateOwner)// play jump animation
{
	Super::OnEnterState(stateOwner);
	mPlant->LaunchCharacter(launchHeight, false, false);
	GetWorld()->GetTimerManager().SetTimer(handle, this, &UDashBackState::LaunchCharacterBack,.05f, false); //
	//mPlant->shouldTrack = false;
}

void UDashBackState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UDashBackState::TickState()
{
	Super::TickState();
}

void UDashBackState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UDashBackState::LaunchCharacterBack()
{
	FVector direction = (mPlant->GetActorForwardVector() * -1) * launchDistance;
	mPlant->LaunchCharacter(direction, false, false);
	// move to strafe
}
