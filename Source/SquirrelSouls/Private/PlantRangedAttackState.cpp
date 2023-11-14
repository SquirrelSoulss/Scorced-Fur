// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRangedAttackState.h"
#include "StateManagerComponent.h"
#include "StationaryPlantClass.h"

void UPlantRangedAttackState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->rangedAttackCall = true;
	thisPlant->GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UPlantRangedAttackState::ShootProjectile, timeToShoot, false);

}

void UPlantRangedAttackState::OnExitState()
{
	thisPlant->rangedAttackCall = false;
	thisPlant->shouldTrack = true;
	thisPlant->changeState = false;
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UPlantRangedAttackState::TickState()
{
	if (thisPlant->changeState == true) {
		thisPlant->stateManager->SwitchStateByKey("Aggro");
	}
}

void UPlantRangedAttackState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UPlantRangedAttackState::ShootProjectile()
{
	thisPlant->ShootProjectile();
}
