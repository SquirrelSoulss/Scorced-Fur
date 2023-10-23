// Fill out your copyright notice in the Description page of Project Settings.


#include "EntHandAttack.h"

void UEntHandAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	EntRef->StartHandAttack();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hand attack"));
}

void UEntHandAttack::OnExitState()
{
}

void UEntHandAttack::TickState(float DeltaTime)
{
	Super::TickState(DeltaTime);
	EntRef->CheckForHit();
}
