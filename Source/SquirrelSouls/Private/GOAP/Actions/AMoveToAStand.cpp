// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/AMoveToAStand.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"

bool UAMoveToAStand::Perform()
{
	/*AAIController* ctrl = Cast<AAIController>(myAgent->GetController());
	ctrl->MoveToLocation(target->GetActorLocation());*/
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Move To stand!"));
	return false;
}

bool UAMoveToAStand::IsDone()
{
	/*if (myAgent->GetActorLocation() == target->GetActorLocation()) {
		return true;
	}*/
	return true; // change to false
}
