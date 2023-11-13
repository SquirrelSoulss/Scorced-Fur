// Fill out your copyright notice in the Description page of Project Settings.


#include "EntComboAttack.h"

void UEntComboAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	EntRef->IsCombo = true;
}

void UEntComboAttack::OnExitState()
{
}

void UEntComboAttack::TickState()
{
}

void UEntComboAttack::InitializeAttacks()
{

}
