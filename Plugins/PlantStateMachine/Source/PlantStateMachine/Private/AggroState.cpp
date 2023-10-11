// Fill out your copyright notice in the Description page of Project Settings.

#include "IPlant.h"
#include "AggroState.h"

void UAggroState::OnEnterState(AActor* stateOwner)
{
    Super::OnEnterState(stateOwner);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Entered AggroState"));
    if (!enemy)
    {
        enemy = Cast<AActor>(stateOwner);
        if (enemy->GetClass()->ImplementsInterface(UIPlant::StaticClass()))
        {
            IIPlant* s = Cast<IIPlant>(enemy);
            //s->DoAttack();
            IIPlant::Execute_TakeDamage(enemy);
           
        }
       
    }
}

void UAggroState::OnExitState()
{
}

void UAggroState::TickState()
{
}
