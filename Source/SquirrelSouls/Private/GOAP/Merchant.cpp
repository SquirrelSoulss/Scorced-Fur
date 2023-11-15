// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Merchant.h"
#include "GOAP/Planner/GOAPPlanner.h"

TMap<FString, bool> AMerchant::GetWorldState_Implementation()
{
	TMap<FString, bool> s;
	s.Add(TEXT("customerWaiting"), true);
	return s;
}

TMap<FString, bool> AMerchant::CreateGoalState_Implementation()
{
	return TMap<FString, bool>();
}

void AMerchant::BeginPlay()
{
	Super::BeginPlay();
	TArray<UGOAPAction*> p = plannerComponent->Plan(this, myAvailableActions, GetWorldState_Implementation(), myGoals[0]->goalState);
	
	for (UGOAPAction* a : p) {
		a->Perform();
	}
}

void AMerchant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMerchant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
