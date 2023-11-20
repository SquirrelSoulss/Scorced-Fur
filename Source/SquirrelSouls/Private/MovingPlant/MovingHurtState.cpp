// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingHurtState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"

void UMovingHurtState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	mPlant->takenDamage = true; //subscribe to attack
	
	if (canDodge == true && FMath::RandRange(0,15) > 9) {
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDodge, 0.2f, false);
		return;
	}
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDecide, timeBetweenTransition, false);
	

}

void UMovingHurtState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	mPlant->takenDamage = false;

	//unsubscribe from attack
}

void UMovingHurtState::TickState()
{
}

void UMovingHurtState::Damaged(float damage)
{
	Super::Damaged(damage);
	
	//mPlant->takenDamage = false;

	//GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDecide, timeBetweenTransition, false);

}

void UMovingHurtState::SwitchToDecide()
{
	mPlant->stateManager->SwitchStateByKey("decide");
}

void UMovingHurtState::SwitchToDodge()
{
	mPlant->stateManager->SwitchStateByKey("dodge");
	canDodge = false;
}
