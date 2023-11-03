// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRangedAttackState.h"
#include "StateManagerComponent.h"
#include "StationaryPlantClass.h"

void UPlantRangedAttackState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->rangedAttackCall = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Ranged"));
}

void UPlantRangedAttackState::OnExitState()
{
	thisPlant->rangedAttackCall = false;
	thisPlant->shouldTrack = true;
	thisPlant->changeState = false;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Exit ranged"));
}

void UPlantRangedAttackState::TickState(float DeltaTime)
{
	if (thisPlant->changeState == true) {
		thisPlant->stateManager->SwitchStateByKey("Aggro");
	}
}
