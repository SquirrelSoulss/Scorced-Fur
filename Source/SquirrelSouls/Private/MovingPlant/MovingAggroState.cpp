// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingAggroState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "AIController.h"
#include "NavigationData.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"
#include <Kismet/GameplayStatics.h>

void UMovingAggroState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner); 
	//sprint toward target 
	if (mainCharacter == nullptr) {
		mainCharacter = UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass());
	}
	aiController->MoveToActor(mainCharacter, 50); // set movementspeed to greater
}

void UMovingAggroState::OnExitState()
{
	Super::OnExitState();
}

void UMovingAggroState::TickState()
{
	Super::TickState();
	if (FVector::Distance(mPlant->GetActorLocation(), mainCharacter->GetActorLocation()) <= 500.f) //turn into variable
	{
		//unleash melee attack
		mPlant->stateManager->SwitchStateByKey("lunge");
	}
}

void UMovingAggroState::Damaged(float damage)
{
	Super::Damaged(damage);
}
