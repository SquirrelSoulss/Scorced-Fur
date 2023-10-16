// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantAggro.h"
#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Math/UnrealMathUtility.h"

void UPlantAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner); //calls baseclass OnEnterState first in order to get some baseline information
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Aggro"));

	if (thisPlant == nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Plant Aggro state should not be availabe to this class"));
	}
	thisPlant->sensesPlayer = true; // senses player connected to animation blueprint, used to change into hostile idle

	float randTime = FMath::RandRange(3, 6);
	thisPlant->GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UPlantAggro::DecideAttack, randTime, false); // randomize the amount of time before the call
}

void UPlantAggro::OnExitState()
{
	thisPlant->GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UPlantAggro::TickState()
{
	FHitResult hit;

	FVector playerLocation = mainCharacter->GetActorLocation();
	FVector plantLocation = thisPlant->GetActorLocation();

	FixRotation(plantLocation, playerLocation);

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(thisPlant);

	thisPlant->GetWorld()->LineTraceSingleByChannel(hit, plantLocation, playerLocation, traceChannel, queryParams);
	DrawDebugLine(thisPlant->GetWorld(), plantLocation, playerLocation, FColor::Red);

	FVector dist = thisPlant->GetActorLocation() - mainCharacter->GetActorLocation();

	float distance = dist.Length();
	if (distance <= 400) {
		thisPlant->stateManager->SwitchStateByKey("MeleeAttack");
	}
	/*if (Cast<MainCharacterBP>(hit.GetActor())) 
	{

	}*/
}

void UPlantAggro::DecideAttack()
{
	thisPlant->stateManager->SwitchStateByKey("RangedAttack");
	
}


