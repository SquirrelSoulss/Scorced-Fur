// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantAggro.h"

void UPlantAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Aggro"));
}

void UPlantAggro::OnExitState()
{
}

void UPlantAggro::TickState()
{
}
