// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootStateBase.h"

void URootStateBase::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	RootRef = Cast<ARootClass>(stateOwner);
	PlayerRef = RootRef->PlayerRef;
}

void URootStateBase::OnExitState()
{
}

void URootStateBase::TickState()
{
	Super::TickState();
}
