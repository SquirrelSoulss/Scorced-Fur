// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantBaseState.h"
#include <Kismet/KismetMathLibrary.h>

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
}

void UPlantBaseState::TickState() // to be called when tick is called
{
}

void UPlantBaseState::FixRotation(FVector actorLocation, FVector targetLocation) // used to make the enemy face player
{
	if (!thisPlant->shouldTrack)
		return;
	FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(actorLocation, targetLocation);
	FRotator newRotation = FMath::RInterpTo(thisPlant->GetActorRotation(), targetRot, thisPlant->GetWorld()->GetTimeSeconds(), 5);
	FRotator doneRotation = FRotator(0, newRotation.Yaw, 0);
	//thisPlant->SetActorRotation(doneRotation);
	thisPlant->targetBoneRotation = doneRotation;
}
