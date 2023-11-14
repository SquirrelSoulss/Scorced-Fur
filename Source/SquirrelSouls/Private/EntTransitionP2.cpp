// Fill out your copyright notice in the Description page of Project Settings.


#include "EntTransitionP2.h"

void UEntTransitionP2::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
}

void UEntTransitionP2::OnExitState()
{
}

void UEntTransitionP2::TickState()
{
}

void UEntTransitionP2::InitializeP2()
{
	HasInitialized = true;

	EntRef->AvailableAttacks.Add({ "SpawnAttack", 10000.f, 0.1f });
	EntRef->AvailableAttacks.Add({ "FireSlamAttack", 700.f, 0.25f });

	if (!EntRef)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("problem"));
	else
	{
		FAvailableCombos Combo2HandFire;
		Combo2HandFire.ComboArray = { "HandAttack", "HandAttack", "FireHandAttack" };
		EntRef->AvailableCombos.Add(Combo2HandFire);
	}

}
