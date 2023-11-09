// Fill out your copyright notice in the Description page of Project Settings.


#include "EntDeath.h"


void UEntDeath::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	EntRef->CanMove = false;
	EntRef->IsAttacking = false;
	EntRef->IsDead = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("dead"));
}

void UEntDeath::OnExitState()
{
}

void UEntDeath::TickState()
{
}
