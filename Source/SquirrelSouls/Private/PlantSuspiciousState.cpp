// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantSuspiciousState.h"
#include "StateManagerComponent.h"

void UPlantSuspiciousState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	thisPlant->GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UPlantSuspiciousState::SwitchToIdle, 3, false); //
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Sus"));
}

void UPlantSuspiciousState::OnExitState()
{
	Super::OnExitState();
	thisPlant->GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UPlantSuspiciousState::TickState()
{
	Super::TickState();
	playerLocation = mainCharacter->GetActorLocation();
	plantLocation = thisPlant->GetActorLocation();
	if (ShootRay(plantLocation, playerLocation) == true && DistanceToPlayer() < AggroRange) {
		thisPlant->stateManager->SwitchStateByKey("Aggro");
		return;
	}
}
		

void UPlantSuspiciousState::SwitchToIdle()
{
	thisPlant->stateManager->SwitchStateByKey("Idle");
}
