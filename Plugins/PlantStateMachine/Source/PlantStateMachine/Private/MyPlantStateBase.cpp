// Fill out your copyright notice in the Description page of Project Settings.

#include "IPlant.h"
#include "MyPlantStateBase.h"

void UMyPlantStateBase::OnEnterState(AActor *stateOwner)
{
    Super::OnEnterState(stateOwner);
    GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Entered BaseState"));
    if(!enemy)
    {
        enemy = Cast<AActor>(stateOwner);
        if(enemy->GetClass()->ImplementsInterface(UIPlant::StaticClass()))
        {
            IIPlant* s = Cast<IIPlant>(enemy);
           // s->DoAttack();
            //IIPlant::Execute_DoAttack(enemy);
            //s->Execute_DoAttack(enemy);
        }
    }
}

void UMyPlantStateBase::OnExitState()
{
}

void UMyPlantStateBase::TickState()
{
}
