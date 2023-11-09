// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingHurtState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"

void UMovingHurtState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->takenDamage = false;

	mPlant->takenDamage = true; //subscribe to attack
	//mPlant->takenDamage = false;

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDecide, timeBetweenTransition, false);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("ENtered damaged"));// error invalid state

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
	mPlant->takenDamage = false;
	//mPlant->takenDamage = false;

	//GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingHurtState::SwitchToDecide, timeBetweenTransition, false);

}

void UMovingHurtState::SwitchToDecide()
{
	mPlant->stateManager->SwitchStateByKey("decide");
}
