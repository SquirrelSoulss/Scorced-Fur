// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/AMoveToAStand.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "AIController.h"
#include "GOAP/Actions/Shop.h"
#include <Kismet/GameplayStatics.h>
#include "Kismet/KismetMathLibrary.h"

bool UAMoveToAStand::Perform(float DeltaTime)
{
	if (dontRunAgain)
		return true;

	AAIController* ctrl = Cast<AAIController>(myAgent->GetController());
	target = UGameplayStatics::GetActorOfClass(GetWorld(), AShop::StaticClass());
	if (target != NULL) {
		ctrl->MoveToActor(target);
	}
		
	dontRunAgain = true;
	
	return false;
}

bool UAMoveToAStand::IsDone()
{	
	if (target == nullptr)
		return true;
	
	//return myAgent->GetVelocity().Length() < 1;
	return FVector::Distance(myAgent->GetActorLocation(), target->GetActorLocation()) < 120.f; // change to false
}

void UAMoveToAStand::AbortAction()
{
	AAIController* ctrl = Cast<AAIController>(myAgent->GetController()) ;
	ctrl->StopMovement();
	dontRunAgain = false;
}

UAMoveToAStand::UAMoveToAStand()
{
	usesDeltaTime = false;
}
