// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlant/MovingDecideState.h"
#include "Math/UnrealMathUtility.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "MovingPlant/MovingStrafeState.h"

void UMovingDecideState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	//youve seen the player decide on wether you should leap backwards, strafe or run towards player
	//leap backwards if player is close and presses the attack button (do this every thrid or so)
	//50/50 between strafe and lunge attack, if player gets close attack
	//tricky could be used when the fight has been going on for a while
	mPlant->shouldTrack = true;
	if (FVector::Distance(mPlant->GetActorLocation(), mainCharacter->GetActorLocation()) <= 500.f){

	}
	if (mPlant->stateManager->StateHistory[0]->IsA(UMovingStrafeState::StaticClass())) {
		//then we should attack one way or another
		ChooseBetweenAttacks();
		return;
	}
	if (FMath::RandRange(0, 7) > 4) {
		mPlant->stateManager->SwitchStateByKey("strafe");
		return;
	}
	ChooseBetweenAttacks();
}

void UMovingDecideState::OnExitState()
{
	Super::OnExitState();
}

void UMovingDecideState::TickState()
{
	Super::TickState();
}

void UMovingDecideState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UMovingDecideState::SubscribedAttack()
{
	// fråga om spelaren ha klickat på attack, har den det, kör en random på typ 3

}

void UMovingDecideState::ChooseBetweenAttacks()
{
	
	mPlant->stateManager->SwitchStateByKey("sprint");
}
