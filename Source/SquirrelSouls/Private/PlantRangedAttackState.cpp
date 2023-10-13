// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRangedAttackState.h"
#include "StateManagerComponent.h"
#include "StationaryPlantClass.h"

void UPlantRangedAttackState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	if (thisPlant == nullptr) {
		thisPlant = Cast<AStationaryPlantClass>(stateOwner);
	}
	mainCharacter = thisPlant->mainCharacter;
	thisPlant->rangedAttackCall = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Ranged"));
}

void UPlantRangedAttackState::OnExitState()
{
	thisPlant->rangedAttackCall = false;
	thisPlant->shouldTrack = true;
}

void UPlantRangedAttackState::TickState()
{
	if (thisPlant->shouldTrack == true) 
	{
		FVector playerLocation = mainCharacter->GetActorLocation();
		FVector plantLocation = thisPlant->GetActorLocation();
		FixRotation(plantLocation, playerLocation);
	}
	else 
	{
		thisPlant->stateManager->SwitchStateByKey("Aggro");

	}
}
