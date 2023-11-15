// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantBaseState.h"
#include <Kismet/KismetMathLibrary.h>
#include "SquirrelSouls/PlayerCharacter.h"
#include "Engine/EngineTypes.h"
#include "StateManagerComponent.h"

void UPlantBaseState::OnEnterState(AActor* stateOwner) // every state who inherits from plantbase will do this when onenter is called
{
	Super::OnEnterState(stateOwner);
	if(thisPlant == nullptr)
		thisPlant = Cast<AStationaryPlantClass>(stateOwner); // gives the states paccess to the plants functionality

	if(mainCharacter == nullptr)
		mainCharacter = thisPlant->mainCharacter; // gives the states player information
}

void UPlantBaseState::OnExitState() //to be called when state exits
{
	Super::OnExitState();
	thisPlant->ResetHurtBox();
}

void UPlantBaseState::TickState() // to be called when tick is called
{
}

void UPlantBaseState::Damaged(float damage)
{
	Super::Damaged(damage);
	thisPlant->health -= damage;
	thisPlant->UpdateHealtbar(damage);

	if (thisPlant->health <= 0) {
		thisPlant->stateManager->SwitchStateByKey("dead");
		return;
	}
	
	thisPlant->stateManager->SwitchStateByKey("hurt");
	//add a bool or call to the baseclass blueprint to play the hurt animation

}




bool UPlantBaseState::ShootRay(FVector origin, FVector end, AActor* ignoredActor)
{
	FHitResult hit;

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(ignoredActor);
	GetWorld()->LineTraceSingleByChannel(hit, origin, end, traceChannel, queryParams);

	DrawDebugLine(GetWorld(), origin, end, FColor::Red);
	
	if (Cast<APlayerCharacter>(hit.GetActor()) != nullptr) // if we are seeing the player
	{
		return true;
	}
	
	return false;
}

float UPlantBaseState::DistanceToPlayer()
{
	return FVector::Distance(plantLocation, playerLocation);
}
