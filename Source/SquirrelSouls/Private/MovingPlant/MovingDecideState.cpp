// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlant/MovingDecideState.h"
#include "Math/UnrealMathUtility.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "MovingPlant/MovingStrafeState.h"
#include "MovingPlant/DashBackState.h"

void UMovingDecideState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->shouldTrack = true;
	if (FVector::Distance(mPlant->GetActorLocation(), mainCharacter->GetActorLocation()) <= 500.f){
		mPlant->stateManager->SwitchStateByKey("sprint");
		return;
	}
	
	if (mPlant->stateManager->StateHistory[0]->IsA(UMovingStrafeState::StaticClass())) {
		ChooseBetweenAttacks();
		return;
	}
	if (FMath::RandRange(0, 7) > 3) {
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
	if (mPlant->stateManager->StateHistory[0]->IsA(UDashBackState::StaticClass())
		&& FMath::RandRange(0, 6) > 3) {
		mPlant->stateManager->SwitchStateByKey("zigzag");
		return;
	}
	if (FMath::RandRange(0, 6) > 3) {
		mPlant->stateManager->SwitchStateByKey("zigzag");
		return;
	}
	mPlant->stateManager->SwitchStateByKey("sprint");
}
