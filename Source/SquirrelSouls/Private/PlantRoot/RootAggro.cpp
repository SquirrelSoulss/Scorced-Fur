// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootAggro.h"

void URootAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	if (RootRef->PlayerIsInRadius)
		RootRef->PlayerInRadius();
}

void URootAggro::OnExitState()
{
}

void URootAggro::TickState()
{
	Super::TickState();
}
