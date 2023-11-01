// Fill out your copyright notice in the Description page of Project Settings.


#include "EntSpawnEnemyAttack.h"
#include "NavigationSystem.h"
#include "TimerManager.h"

void UEntSpawnEnemyAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Orange, TEXT("Spawn Enemy"));

	EntRef->StartSpawnAttack();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_SpawnEnemy, this, &UEntSpawnEnemyAttack::SpawnEnemy, SpawnIntervall, true, 5.f);
}

void UEntSpawnEnemyAttack::OnExitState()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_SpawnEnemy);
}

void UEntSpawnEnemyAttack::TickState(float DeltaTime)
{
}

void UEntSpawnEnemyAttack::SpawnEnemy()
{
	FVector NewDestination;
	if (GetRandomPoint(EntRef->GetActorLocation(), RandomPointRadius, NewDestination))
	{
		if (EntRef->CanSpawn)
			EntRef->SpawnEnemy(nullptr, NewDestination);
	}
}

bool UEntSpawnEnemyAttack::GetRandomPoint(const FVector& Origin, float Radius, FVector& OutLocation)
{
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(EntRef);
	if (NavSystem)
	{
		FNavLocation RandomTargetLocation;
		if (NavSystem->GetRandomReachablePointInRadius(Origin, Radius, RandomTargetLocation))
		{
			OutLocation = RandomTargetLocation.Location;
			return true;
		}
	}
	return false;
}
