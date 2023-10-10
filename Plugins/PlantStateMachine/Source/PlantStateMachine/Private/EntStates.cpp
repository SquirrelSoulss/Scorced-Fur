// Fill out your copyright notice in the Description page of Project Settings.


#include "EntStates.h"

void UEntStates::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	if (!enemy)
	{
		enemy = Cast<AActor>(enemy);
	}
}

void UEntStates::OnExitState()
{
}

void UEntStates::TickState()
{
}
