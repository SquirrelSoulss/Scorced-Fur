// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantAggro.h"
#include "EnemyBaseClass.h"
#include "Kismet/KismetMathLibrary.h"

void UPlantAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	enemy = stateOwner;
	thisPlant = Cast<AEnemyBaseClass>(enemy);

	if (thisPlant == nullptr) 
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Plant Aggro state should not be availabe to this class"));
	}
	thisPlant->sensesPlayer = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("ISee player"));
	mainCharacter = thisPlant->mainCharacter;
}

void UPlantAggro::OnExitState()
{
}

void UPlantAggro::TickState()
{
	FHitResult hit;

	FVector playerLocation = mainCharacter->GetActorLocation();
	FVector plantLocation = thisPlant->GetActorLocation();

	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(thisPlant);

	thisPlant->GetWorld()->LineTraceSingleByChannel(hit, plantLocation, playerLocation, traceChannel, queryParams);
	DrawDebugLine(thisPlant->GetWorld(), plantLocation, playerLocation, FColor::Red);

	/*if (Cast<MainCharacterBP>(hit.GetActor())) 
	{

	}*/
	FixRotation(plantLocation, playerLocation);
}

void UPlantAggro::FixRotation(FVector actorLocation, FVector targetLocation)
{
	FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(actorLocation, targetLocation);
	FRotator newRotation = FMath::RInterpTo(thisPlant->GetActorRotation(), targetRot, thisPlant->GetWorld()->GetTimeSeconds(), 3);
	thisPlant->SetActorRotation(newRotation);
}
