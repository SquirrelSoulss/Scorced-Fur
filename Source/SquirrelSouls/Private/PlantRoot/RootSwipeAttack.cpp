// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootSwipeAttack.h"

void URootSwipeAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	RootRef->AnimRef->IsSwipeAttack = true;
	RootRef->ShouldRotate = true;
	RootRef->PlayerInRadiusCooldown = false;
}

void URootSwipeAttack::OnExitState()
{
}

void URootSwipeAttack::TickState()
{
}
