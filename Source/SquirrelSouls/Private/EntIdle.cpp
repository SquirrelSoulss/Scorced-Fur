// Fill out your copyright notice in the Description page of Project Settings.


#include "EntIdle.h"

void UEntIdle::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Idle"));
}

void UEntIdle::OnExitState()
{
}

void UEntIdle::TickState()
{
}
