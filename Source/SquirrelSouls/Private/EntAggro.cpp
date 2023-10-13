// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAggro.h"

void UEntAggro::OnEnterState(AActor* stateOwner)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Aggro"));

}

void UEntAggro::OnExitState()
{
}

void UEntAggro::TickState()
{
}

