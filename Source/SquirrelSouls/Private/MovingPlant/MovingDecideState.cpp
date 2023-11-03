// Fill out your copyright notice in the Description page of Project Settings.


#include "Math/UnrealMathUtility.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "MovingPlant/MovingDecideState.h"

void UMovingDecideState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	//youve seen the player decide on wether you should leap backwards, strafe or run towards player
	//leap backwards if player is close and presses the attack button (do this every thrid or so)
	//50/50 between strafe and lunge attack, if player gets close attack

	if (FMath::RandRange(0, 7) > 4) {
		mPlant->stateManager->SwitchStateByKey("strafe");
		return;
	}
	mPlant->stateManager->SwitchStateByKey("lunge");
}

void UMovingDecideState::OnExitState()
{
	Super::OnExitState();
}

void UMovingDecideState::TickState()
{
}

void UMovingDecideState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UMovingDecideState::SubscribedAttack()
{
	// fråga om spelaren ha klickat på attack, har den det, kör en random på typ 3

}
