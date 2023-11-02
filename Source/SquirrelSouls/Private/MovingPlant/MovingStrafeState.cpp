// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingStrafeState.h"
#include "AIController.h"
#include "Math/UnrealMathUtility.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

void UMovingStrafeState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Strafe"));
	mPlant->GetCharacterMovement()->MaxWalkSpeed = mPlant->walkSpeed - 100;
	aiController->SetFocus(mainCharacter);
	Strafe();
}

void UMovingStrafeState::OnExitState()
{
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	mPlant->GetCharacterMovement()->MaxWalkSpeed = mPlant->maxMovementSpeed;
	aiController->ClearFocus(EAIFocusPriority::Gameplay);
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
	float randomDirection = 1;
	if (FMath::RandRange(0,2) == 1)
		randomDirection = -1;
	
	FVector destination = mPlant->GetActorLocation() + (mPlant->GetActorForwardVector() * 50.f) + 
		mPlant->GetActorRightVector() * (randomDirection * 300) ;
	aiController->MoveToLocation(destination);

	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingStrafeState::ChangeToLeapAttack, 3.f, false);
}

void UMovingStrafeState::ChangeToLeapAttack()
{
	mPlant->stateManager->SwitchStateByKey("sus");
}
