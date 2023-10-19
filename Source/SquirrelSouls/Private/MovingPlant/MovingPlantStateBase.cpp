// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingPlantStateBase.h"

void UMovingPlantStateBase::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	if (thisMovingPlant == nullptr)
		thisMovingPlant = Cast<AMovingPlantClass>(stateOwner);
	if (aiController == nullptr)
		aiController = Cast<AAIController>(thisMovingPlant->GetController());
}

void UMovingPlantStateBase::OnExitState()
{
	Super::OnExitState();
}

void UMovingPlantStateBase::TickState()
{
	Super::TickState();
}

void UMovingPlantStateBase::PlayerOverlapping()
{
	Super::PlayerOverlapping();
}
