// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAttackingP1.h"

void UEntAttackingP1::OnEnterState(AActor* stateOwner)
{
	EntRef = Cast<AEntClass>(stateOwner);
	playerRef = EntRef->playerRef;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("isAttacking"));

}

void UEntAttackingP1::OnExitState()
{
}

void UEntAttackingP1::TickState()
{
	if (EntRef->IsAttacking)
		EntRef->CheckForHit();
	else
		EntRef->SwitchState("Aggro");
}
