// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAggro.h"
#include "Kismet/KismetMathLibrary.h"

void UEntAggro::OnEnterState(AActor* stateOwner)
{
	bCanTickState = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Aggro"));

	AEntClass* ent = Cast<AEntClass>(stateOwner);
	if (ent) {
		entRef = ent;
	}
	entRef->MoveToPlayer();
}

void UEntAggro::OnExitState()
{
}

void UEntAggro::TickState()
{
	FHitResult hit;
	FCollisionQueryParams queryParams;
	queryParams.AddIgnoredActor(entRef);

	entRef->GetWorld()->LineTraceSingleByChannel(hit, entRef->GetActorLocation(), playerRef->GetActorLocation(), traceChannel, queryParams);
	DrawDebugLine(entRef->GetWorld(), entRef->GetActorLocation(), playerRef->GetActorLocation(), FColor::Red);
}

void UEntAggro::ChooseAttackP1()
{

}

