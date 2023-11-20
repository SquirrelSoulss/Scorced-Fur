// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantAggro.h"
#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "SquirrelSouls/PlayerCharacter.h"
#include "Math/UnrealMathUtility.h"

void UPlantAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner); //calls baseclass OnEnterState first in order to get some baseline information
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Aggro"));
	thisPlant->aturnSpeed = 10.f;
	if (thisPlant == nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Plant Aggro state should not be availabe to this class"));
	}
	thisPlant->sensesPlayer = true; // senses player connected to animation blueprint, used to change into hostile idle
	thisPlant->shouldTrack = true;

	float randTime = FMath::RandRange(2, 4);
	thisPlant->GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UPlantAggro::RangedAttack, randTime, false); // randomize the amount of time before the call
}

void UPlantAggro::OnExitState()
{
	thisPlant->GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UPlantAggro::TickState()
{
	playerLocation = mainCharacter->GetActorLocation();
	plantLocation = thisPlant->GetActorLocation();

	//FixRotation(plantLocation, playerLocation);

	if (ShootRay(plantLocation, playerLocation, thisPlant) == false || DistanceToPlayer() >= AggroRange) // or player is to far away
	{
		thisPlant->stateManager->SwitchStateByKey("Suspicious");
		return;
	}

	if (DistanceToPlayer() <= 400) {
		thisPlant->stateManager->SwitchStateByKey("MeleeAttack");
	}
}

void UPlantAggro::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UPlantAggro::RangedAttack()
{
	thisPlant->stateManager->SwitchStateByKey("RangedAttack");
}


