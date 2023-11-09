// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingHurtState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"

void UMovingHurtState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->takenDamage = true; //subscribe to attack
}

void UMovingHurtState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	//unsubscribe from attack
}

void UMovingHurtState::TickState()
{
}

void UMovingHurtState::Damaged(float damage)
{
	Super::Damaged(damage);
	mPlant->takenDamage = true;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDecide, 0.2f, false);

}

void UMovingHurtState::SwitchToDecide()
{
	mPlant->stateManager->SwitchStateByKey("decide");
}
