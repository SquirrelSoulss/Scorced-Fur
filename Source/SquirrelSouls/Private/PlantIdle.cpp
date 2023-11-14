// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantIdle.h"
#include "StationaryPlantClass.h"

void UPlantIdle::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Idle"));
	thisPlant->shouldTrack = false;
}

void UPlantIdle::OnExitState()
{
	
}

void UPlantIdle::TickState()
{
}

void UPlantIdle::Damaged(float damage)
{
}
