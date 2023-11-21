// Fill out your copyright notice in the Description page of Project Settings.


#include "EntStompAttack.h"

void UEntStompAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	EntRef->StartStompAttack(EntRef->IsCombo);
}

void UEntStompAttack::OnExitState()
{
}

void UEntStompAttack::TickState()
{
}
