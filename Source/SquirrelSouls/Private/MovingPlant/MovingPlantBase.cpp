// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingPlantBase.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"


void UMovingPlantBase::OnEnterState(AActor* stateOwner)
{
	if (mPlant == nullptr)
		mPlant = Cast<AMovingPlantClass>(stateOwner);
	if (mainCharacter == nullptr)
		mainCharacter = mPlant->mainCharacter;
	if (aiController == nullptr)
		aiController = Cast<AAIController>(mPlant->GetController());
}

void UMovingPlantBase::OnExitState()
{
	Super::OnExitState();
	aiController->StopMovement();
}

void UMovingPlantBase::TickState()
{
	Super::TickState();
}

void UMovingPlantBase::Damaged(float damage)
{
	//Super::Damaged(damage);
	//deal damager equal to damage
	mPlant->stateManager->SwitchStateByKey("hurt");
}
