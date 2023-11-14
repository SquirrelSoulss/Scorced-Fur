// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/PlantDeadState.h"
#include "EnemyBaseClass.h"

void UPlantDeadState::OnEnterState(AActor* stateOwner)
{
	AEnemyBaseClass* plant = Cast<AEnemyBaseClass>(stateOwner);
	
	if (plant != NULL) {
		plant->shouldTrack = false;
		plant->dead = true;

	}
	//start the mesh disintegration and what not
}

void UPlantDeadState::OnExitState()
{
	
}

void UPlantDeadState::TickState()
{
}

void UPlantDeadState::Damaged(float damage)
{
}
