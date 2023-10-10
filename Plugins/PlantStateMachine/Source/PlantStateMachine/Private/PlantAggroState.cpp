// Fill out your copyright notice in the Description page of Project Settings.

#include "IPlant.h"
#include "PlantAggroState.h"

void UPlantAggroState::OnEnterState(AActor* stateOwner)
{
    if (!enemy)
    {
        enemy = Cast<AActor>(stateOwner);
        if (enemy->GetClass()->ImplementsInterface(UIPlant::StaticClass()))
        {
            IIPlant* s = Cast<IIPlant>(enemy);
            s->DoAttack();
            IIPlant::Execute_TakeDamage(enemy);
        }
    }
}

void UPlantAggroState::OnExitState()
{
}

void UPlantAggroState::TickState()
{
}
