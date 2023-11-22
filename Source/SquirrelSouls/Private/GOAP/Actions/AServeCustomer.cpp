// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/AServeCustomer.h"
#include "GOAP/Labourer.h"
#include"SquirrelSouls/PlayerCharacter.h"
#include "GOAP/Merchant.h" 
#include "Kismet/GameplayStatics.h"


bool UAServeCustomer::Perform(float DeltaTime)
{
	if (!runAgain)
		return true;
	runAgain = false;
	AMerchant* a = Cast<AMerchant>(myAgent);
	a->isIdlyWaiting = true;
	
	GetWorld()->GetTimerManager().SetTimer(timerHandle, this, &UAServeCustomer::GivePotions, .5f, false);
	//Play idle animation set the world state to serving customer or something
	return false;
}

bool UAServeCustomer::IsDone()
{
	
	return true; //change to false
}

void UAServeCustomer::AbortAction()
{
	AMerchant* a = Cast<AMerchant>(myAgent);
	GetWorld()->GetTimerManager().ClearTimer(timerHandle);
	a->isIdlyWaiting = false;
	runAgain = true;
}

void UAServeCustomer::GivePotions()
{
	if (givenPotions)
		return;
	APlayerCharacter* character;
	character = Cast<APlayerCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCharacter::StaticClass()));
	if (character == nullptr)
		return;
	character->GetHealthPotions(3);
	givenPotions = true;
}
