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
	if (handlesDamageSeparately)
	{
		return;
	}
	mPlant->health -= damage;
	// flash effect for damage
	if(mPlant->health <= 0)
		//death
	
	if(canBeStaggered)
		mPlant->stateManager->SwitchStateByKey("hurt");
}
