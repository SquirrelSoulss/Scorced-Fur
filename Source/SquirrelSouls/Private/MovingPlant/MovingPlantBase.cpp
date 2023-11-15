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
	aiController->StopMovement();
	mPlant->ResetHurtBox();
}

void UMovingPlantBase::TickState()
{
	
}

void UMovingPlantBase::Damaged(float damage)
{
	mPlant->health -= damage;
	// flash effect for damage
	mPlant->UpdateHealtbar(damage);
	if (mPlant->health <= 0) {
		mPlant->stateManager->SwitchStateByKey("dead");
		return;
	}

		//death
	
	if(canBeStaggered)
		mPlant->stateManager->SwitchStateByKey("hurt");
}
