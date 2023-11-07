// Fill out your copyright notice in the Description page of Project Settings.


#include "EntP2Aggro.h"

void UEntP2Aggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("Aggro P2"));

	AddAvailableAttacks();
	EntRef->ChilloutPeriod = 1.f;
}

void UEntP2Aggro::OnExitState()
{
}

void UEntP2Aggro::TickState()
{
}

void UEntP2Aggro::AddAvailableAttacks()
{
	AvailableAttacks.Add({ "SpawnAttack", 3000.f, 0.33f });
}
