// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingStrafeState.h"
#include "AIController.h"
#include "Math/UnrealMathUtility.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <Kismet/KismetMathLibrary.h>

void UMovingStrafeState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	mPlant->GetCharacterMovement()->MaxWalkSpeed = mPlant->walkSpeed - 100;
	mPlant->GetCharacterMovement()->bOrientRotationToMovement = false;
	mPlant->GetCharacterMovement()->bUseControllerDesiredRotation = true;
	aiController->SetFocus(mainCharacter);
	mPlant->shouldTrack = true;
	Strafe();
}

void UMovingStrafeState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	mPlant->GetCharacterMovement()->MaxWalkSpeed = mPlant->maxMovementSpeed;
	mPlant->GetCharacterMovement()->bOrientRotationToMovement = true;
	mPlant->GetCharacterMovement()->bUseControllerDesiredRotation = false;


	aiController->ClearFocus(EAIFocusPriority::Gameplay);
	depth = 0;
}

void UMovingStrafeState::TickState()
{
	
}

void UMovingStrafeState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UMovingStrafeState::Strafe()
{
	if (depth >= FMath::RandRange(2, 3))
	{
		ChangeToLeapAttack();
		return;
	}
	float randomDirection = 1;
	if (FMath::RandRange(0,2) == 1)
		randomDirection = -1;
	
	FVector destination = mPlant->GetActorLocation() + (mPlant->GetActorForwardVector() * 50.f) + 
		mPlant->GetActorRightVector() * (randomDirection * 350) ;

	aiController->MoveToLocation(destination);

	depth++;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingStrafeState::Strafe, timeTonextStrafe, false);

}

void UMovingStrafeState::ChangeToLeapAttack()
{
	// decide
	mPlant->stateManager->SwitchStateByKey("decide");
}
