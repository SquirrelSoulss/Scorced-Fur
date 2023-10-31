// Fill out your copyright notice in the Description page of Project Settings.


#include "EntSpawnEnemyAttack.h"

void UEntSpawnEnemyAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Spawn Enemy"));

	EntRef->StartSpawnAttack();

}

void UEntSpawnEnemyAttack::OnExitState()
{
}

void UEntSpawnEnemyAttack::TickState(float DeltaTime)
{
}
