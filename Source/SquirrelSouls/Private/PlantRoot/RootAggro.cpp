// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootAggro.h"

void URootAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	RootRef->ShouldRotate = true;
}

void URootAggro::OnExitState()
{
}

void URootAggro::TickState()
{
	Super::TickState();

	if (RootRef->PlayerIsInRadius && !RootRef->PlayerInRadiusCooldown)
	{
		RootRef->PlayerInRadiusCooldown = true;
		RootRef->PlayerInRadius();
	}
}
