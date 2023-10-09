// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlantStateBase.h"

void UMyPlantStateBase::OnEnterState(AActor *stateOwner)
{
    Super::OnEnterState(stateOwner);

    if(!enemy)
    {
        enemy = Cast<AActor>(enemy);
    }
}

void UMyPlantStateBase::OnExitState()
{
}

void UMyPlantStateBase::TickState()
{
}
