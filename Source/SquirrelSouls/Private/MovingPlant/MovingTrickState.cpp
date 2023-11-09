// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlant/MovingTrickState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"

void UMovingTrickState::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	originalGravityscale = mPlant->GetCharacterMovement()->GravityScale;
	mPlant->GetCharacterMovement()->GravityScale = gravityDuringJump;
	ZigZag();
}

void UMovingTrickState::OnExitState()
{
	Super::OnExitState();
	depth = 1;
	mPlant->GetCharacterMovement()->GravityScale = originalGravityscale;
	GetWorld()->GetTimerManager().ClearAllTimersForObject(this);
}

void UMovingTrickState::TickState()
{
}

void UMovingTrickState::Damaged(float damage)
{
	Super::Damaged(damage);
}

void UMovingTrickState::ZigZag()
{
	mPlant->LaunchCharacter(launchHeight, false, false);
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingTrickState::Forwards, 0.1f, false);
}

void UMovingTrickState::SwitchToAggro()
{
	mPlant->stateManager->SwitchStateByKey("sprint");
}

void UMovingTrickState::Forwards()
{
	FVector horizontalDirection = (mPlant->GetActorRightVector() * launchDistance);
	FVector forwardDirection = mPlant->GetActorForwardVector() * (launchDistanceForward);

	if (depth % 2 == 0) {
		horizontalDirection *= -1;
	}
	if (depth == 1) {
		horizontalDirection /= 2;
	}

	FVector direction = horizontalDirection + forwardDirection;

	mPlant->LaunchCharacter(direction, false, false);
	if (depth == 2) {
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingTrickState::SwitchToAggro, timeToSwitch, false);
	}
	else {
		GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UMovingTrickState::ZigZag, timeBetweenJumps, false);
	}
	depth++;

}
