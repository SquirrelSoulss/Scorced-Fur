// Fill out your copyright notice in the Description page of Project Settings.


#include "EntTransitionP2.h"

void UEntTransitionP2::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	EntRef->ChilloutPeriod -= 0.5f;
}

void UEntTransitionP2::OnExitState()
{
}

void UEntTransitionP2::TickState()
{
	EntRef->CheckFireTransition();
}

void UEntTransitionP2::InitializeP2()
{
	HasInitialized = true;

	EntRef->AvailableAttacks.Add({ "FireSlamAttack", 600.f, 0.25f });

	if (!EntRef)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("problem, no entref"));
	else
	{
		FAvailableCombos newCombo;

		newCombo.isFire = true;
		newCombo.ComboArray = { "HandAttack", "HandAttack", "FireHandAttack" };
		EntRef->AvailableCombos.Add(newCombo);

		newCombo.isFire = true;
		newCombo.ComboArray = { "HandAttack", "StompAttack", "HandAttack", "StompAttack" };
		EntRef->AvailableCombos.Add(newCombo);

		newCombo.isFire = true;
		newCombo.ComboArray = { "StompAttack", "StompAttack","FireHandAttack" };
		EntRef->AvailableCombos.Add(newCombo);
	}

}
