// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantMeleeAttack.h"
#include "StateManagerComponent.h"
#include "StationaryPlantClass.h"

void UPlantMeleeAttack::OnEnterState(AActor* stateOwner) 
{
	Super::OnEnterState(stateOwner);
	thisPlant->meleeAttackTrigger = true; // used to trigger melee attack animation
	thisPlant->aturnSpeed = 10.f;
}

void UPlantMeleeAttack::OnExitState()
{
	thisPlant->meleeAttackTrigger = false; // reset value
	thisPlant->shouldTrack = true; // should track is wether or not the plant should rotate towards the player, gets turned off midway through melee attack
	thisPlant->changeState = false; // reset value off change state 
	thisPlant->ResetHurtBox();
}

void UPlantMeleeAttack::TickState()
{

	if (thisPlant->changeState == true) { // chenge state gets set to true at the end of the animation 
		thisPlant->stateManager->SwitchStateByKey("Aggro"); //wich makes the plant go back to aggro state in order to decide what to do next
	}
}

void UPlantMeleeAttack::Damaged(float damage)
{
	Super::Damaged(damage);
}
