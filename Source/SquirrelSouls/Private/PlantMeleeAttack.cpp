// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantMeleeAttack.h"
#include "StateManagerComponent.h"
#include "StationaryPlantClass.h"

void UPlantMeleeAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->meleeAttackTrigger = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Melee"));
}

void UPlantMeleeAttack::OnExitState()
{
	thisPlant->meleeAttackTrigger = false;
	thisPlant->shouldTrack = true;
	thisPlant->changeState = false;
}

void UPlantMeleeAttack::TickState()
{
	FVector playerLocation = mainCharacter->GetActorLocation();
	FVector plantLocation = thisPlant->GetActorLocation();
	FixRotation(plantLocation, playerLocation);

	if (thisPlant->changeState == true) {
		thisPlant->stateManager->SwitchStateByKey("Aggro");
	}
}
