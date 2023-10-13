// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantBaseState.h"
#include <Kismet/KismetMathLibrary.h>

void UPlantBaseState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
}

void UPlantBaseState::OnExitState()
{
	Super::OnExitState();
}

void UPlantBaseState::TickState()
{
	Super::TickState();
}

void UPlantBaseState::FixRotation(FVector actorLocation, FVector targetLocation)
{
	FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(actorLocation, targetLocation);
	FRotator newRotation = FMath::RInterpTo(thisPlant->GetActorRotation(), targetRot, thisPlant->GetWorld()->GetTimeSeconds(), 5);
	FRotator doneRotation = FRotator(0, newRotation.Yaw, 0);
	//thisPlant->SetActorRotation(doneRotation);
	thisPlant->targetBoneRotation = doneRotation;
}
