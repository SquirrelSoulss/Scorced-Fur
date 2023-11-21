// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Merchant.h"
#include "GOAP/Planner/GOAPPlanner.h"

TMap<FString, bool> AMerchant::GetWorldState()
{
	
	return myWorldState;
}

TMap<FString, bool> AMerchant::CreateGoalState()
{
	return TMap<FString, bool>();
}

void AMerchant::BeginPlay()
{
	Super::BeginPlay();
	bestGoal = GetBestGoal();
	currentGoal = bestGoal;
	currentPlan = plannerComponent->Plan(this, myAvailableActions, GetWorldState(), bestGoal -> goalState);
	
}

void AMerchant::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	bestGoal = GetBestGoal();
	if (currentGoal == nullptr || bestGoal != currentGoal) {
		currentGoal = bestGoal;
		currentPlan = plannerComponent->Plan(this, myAvailableActions, GetWorldState(), currentGoal->goalState);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("new plan!"));

	}
	else
		FollowPlan(DeltaTime);
	
}

void AMerchant::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}
