// Fill out your copyright notice in the Description page of Project Settings.


#include "EntP2Aggro.h"

void UEntP2Aggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("Aggro P2"));

	if (!HasInitialized)
		InitializePhase2();
}

void UEntP2Aggro::OnExitState()
{
}

void UEntP2Aggro::TickState()
{
}

void UEntP2Aggro::InitializePhase2()
{
	HasInitialized = true;

	AvailableAttacks.Add({ "SpawnAttack", 10000.f, 0.3f });
	AvailableAttacks.Add({ "FireHandAttack", 700.f, 0.7f });
}
