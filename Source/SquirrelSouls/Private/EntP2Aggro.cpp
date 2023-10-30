// Fill out your copyright notice in the Description page of Project Settings.


#include "EntP2Aggro.h"

void UEntP2Aggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	AddAvailableAttacks();
}

void UEntP2Aggro::OnExitState()
{
}

void UEntP2Aggro::TickState(float DeltaTime)
{
}

void UEntP2Aggro::AddAvailableAttacks()
{
	AvailableAttacks.Add({ "Spawn", 3000.f, 0.33f });
}
