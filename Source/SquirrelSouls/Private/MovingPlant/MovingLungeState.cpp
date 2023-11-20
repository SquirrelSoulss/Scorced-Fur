// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingLungeState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"


void UMovingLungeState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	//mPlant->shouldTrack = false;
	mPlant->attackTrigger = true;

	originalGravityscale = mPlant->GetCharacterMovement()->GravityScale;
	mPlant->GetCharacterMovement()->GravityScale = gravityDuringJump;
	
	mPlant->LaunchCharacter(launchHeight, false, false); //launches upward
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingLungeState::LaunchTowardsPlayer, transitionToForwardLaunch, false);
}

void UMovingLungeState::OnExitState()
{
	mPlant->GetCharacterMovement()->GravityScale = originalGravityscale;
	mPlant->ResetHurtBox();
	Super::OnExitState();
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
	mPlant->attackTrigger = false;
}

void UMovingLungeState::TickState()
{
	Super::TickState();
}

void UMovingLungeState::Damaged(float damage)
{
	Super::Damaged(damage); // maybe we dont call super so that we dont get interuppted
}

void UMovingLungeState::LaunchTowardsPlayer()
{
	mPlant->aturnSpeed = 10.f;
	FVector direction = (mainCharacter->GetActorLocation() - mPlant->GetActorLocation()); // maybe send them to a slight right 
	direction.Normalize();
	direction *= launchDistance;
	mPlant->LaunchCharacter(FVector(direction.X, direction.Y, 0), false, false);
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingLungeState::ChangeToStrafe, transitionTime, false);
}

void UMovingLungeState::ChangeToStrafe()
{
	mPlant->stateManager->SwitchStateByKey("strafe");
}
