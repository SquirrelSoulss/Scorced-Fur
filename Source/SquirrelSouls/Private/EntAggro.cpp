// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAggro.h"
#include "Kismet/KismetMathLibrary.h"

void UEntAggro::OnEnterState(AActor* stateOwner)
{
	bCanTickState = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Aggro"));

	EntRef = Cast<AEntClass>(stateOwner);
	playerRef = EntRef->playerRef;

	queryParams.AddIgnoredActor(EntRef);

	EntRef->MoveToPlayer();
}

void UEntAggro::OnExitState()
{
}

void UEntAggro::TickState()
{
	FHitResult hit;

	if (EntRef && playerRef)
	{
		EntRef->GetWorld()->LineTraceSingleByChannel(hit, EntRef->GetActorLocation(), playerRef->GetActorLocation(), traceChannel, queryParams);
		DrawDebugLine(EntRef->GetWorld(), EntRef->GetActorLocation(), playerRef->GetActorLocation(), FColor::Red);

		float distance = hit.Distance;

		EntRef->ChooseAttack(distance);
	}
}

void UEntAggro::ChooseAttackP1()
{

}

