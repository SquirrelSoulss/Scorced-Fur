// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/GOAPFixRotation.h"
#include "GameFramework/Character.h"
#include <Kismet/GameplayStatics.h>
#include "GOAP/Actions/Shop.h"

bool UGOAPFixRotation::Perform(float DeltaTime)
{
	if(target == nullptr)
		target = UGameplayStatics::GetActorOfClass(GetWorld(), AShop::StaticClass());
	myAgent->SetActorRotation(FMath::RInterpTo(myAgent->GetActorRotation(), target->GetActorRotation(), DeltaTime, 2));
	return false;
}

bool UGOAPFixRotation::IsDone()
{
	return myAgent->GetActorRotation().Equals(target->GetActorRotation(),1.f) ;
	
}
