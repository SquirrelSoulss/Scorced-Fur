// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingIdleState.h"
#include "AIController.h"
#include "NavigationData.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include "TimerManager.h"

void UMovingIdleState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->shouldTrack = false;
	mPlant->CallGetPatrolPoint();
	IsReachablePoint(mPlant->randomPoint, 1);

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingIdleState::StartAiMoveTo, 5.f, false); //Make random time
}

void UMovingIdleState::OnExitState()
{
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
}

void UMovingIdleState::TickState()
{

	//ShootRay(mPlant->GetActorLocation(), p, mPlant);
}

void UMovingIdleState::Damaged(float damage)
{
	Super::Damaged(damage * 1.5f); // idle state 
}

void UMovingIdleState::IsReachablePoint(FVector position, int32 depth)
{
	if (depth >= 10) {
		mPlant->randomPoint = mPlant->GetActorLocation();
		return;
	}

	UNavigationPath* aPath = UNavigationSystemV1::FindPathToLocationSynchronously(mPlant->GetWorld(), mPlant->GetActorLocation(), position, NULL);
	if (!aPath) {
		mPlant->CallGetPatrolPoint();
		IsReachablePoint(mPlant->randomPoint, depth + 1);
		return;
	}
	
}

void UMovingIdleState::StartAiMoveTo()
{
	//randomize if this actualy happens
	aiController->MoveToLocation(mPlant->randomPoint, 50.f);
}
