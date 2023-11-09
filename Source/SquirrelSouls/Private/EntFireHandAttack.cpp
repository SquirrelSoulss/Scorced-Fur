// Fill out your copyright notice in the Description page of Project Settings.


#include "EntFireHandAttack.h"

void UEntFireHandAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	EntRef->StartFireSlamAttack();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Emerald, TEXT("eldigt"));

}

void UEntFireHandAttack::OnExitState()
{
}

void UEntFireHandAttack::TickState()
{
}
