// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootNormalAttack.h"

void URootNormalAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	RootRef->AnimRef->IsNormalAttack = true;
}

void URootNormalAttack::OnExitState()
{
}

void URootNormalAttack::TickState(float DeltaTime)
{
	Super::TickState(DeltaTime);

	RootRef->CheckIfHit();
}
