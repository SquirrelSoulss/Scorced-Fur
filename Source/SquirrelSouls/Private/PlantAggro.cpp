// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantAggro.h"
#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UPlantAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	enemy = stateOwner;
	thisPlant = Cast<AStationaryPlantClass>(enemy);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Entered Aggro"));

	if (thisPlant == nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Plant Aggro state should not be availabe to this class"));
	}
	thisPlant->sensesPlayer = true;

	mainCharacter = thisPlant->mainCharacter;

	//thisPlant->GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UPlantAggro::DecideAttack, 7, false);
}

void UPlantAggro::OnExitState()
{
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

	/*if (Cast<MainCharacterBP>(hit.GetActor())) 
	{

	}*/
}

void UPlantAggro::DecideAttack()
{
	thisPlant->stateManager->SwitchStateByKey("RangedAttack");
}


