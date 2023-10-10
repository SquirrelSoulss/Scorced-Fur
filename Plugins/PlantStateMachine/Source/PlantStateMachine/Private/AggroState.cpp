// Fill out your copyright notice in the Description page of Project Settings.

#include "IPlant.h"
#include "AggroState.h"

void UAggroState::OnEnterState(AActor* stateOwner)
{
    if (!enemy)
    {
        enemy = Cast<AActor>(stateOwner);
        if (enemy->GetClass()->ImplementsInterface(UIPlant::StaticClass()))
        {
            IIPlant* s = Cast<IIPlant>(enemy);
            s->DoAttack();
            IIPlant::Execute_DoAttack(enemy);
        }
    }
}

void UAggroState::OnExitState()
{
}

void UAggroState::TickState()
{
}
