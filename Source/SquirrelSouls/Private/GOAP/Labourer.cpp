// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Labourer.h"

// Sets default values
ALabourer::ALabourer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ALabourer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALabourer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ALabourer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

TMap<FString, bool> ALabourer::GetWorldState_Implementation()
{
	return TMap<FString, bool>();
}

TMap<FString, bool> ALabourer::CreateGoalState_Implementation()
{
	return TMap<FString, bool>();
}

void ALabourer::PlanFailed(TMap<FString, bool> failedGoal)
{
}

void ALabourer::PlanFound(TMap<FString, bool> goal, TArray<UGOAPAction*> actions)
{
}

void ALabourer::ActionsFinished_Implementation()
{
}

void ALabourer::PlanAborted_Implementation(UGOAPAction* aborter)
{
}

bool ALabourer::MoveAgent_Implementation(UGOAPAction* nextAction)
{

	return false;
}

