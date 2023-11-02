// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootDeath.h"

void URootDeath::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	RootRef->AnimRef->IsDead = true;
}

void URootDeath::OnExitState()
{
}

void URootDeath::TickState(float DeltaTime)
{
}
