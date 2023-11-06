// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootNormalAttack.h"

void URootNormalAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	RootRef->AnimRef->IsNormalAttack = true;
	RootRef->ShouldRotate = true;

}

void URootNormalAttack::OnExitState()
{
}

void URootNormalAttack::TickState()
{
	Super::TickState();

	//RootRef->CheckIfHit();
}
