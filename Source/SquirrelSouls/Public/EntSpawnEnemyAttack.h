// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntSpawnEnemyAttack.generated.h"

/**
 *
 */
UCLASS()
class SQUIRRELSOULS_API UEntSpawnEnemyAttack : public UEntStateBase
{
	GENERATED_BODY()

	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;

private:
	FVector CurrentLocation;

	FTimerHandle TimerHandle_SpawnEnemy;

public:
	UPROPERTY(EditAnywhere)
	float RandomPointRadius = 1000.f;

	UPROPERTY(EditAnywhere)
	float IdleIntervall = 10.f;

	UFUNCTION()
	void SpawnEnemy();
	bool GetRandomPoint(const FVector& Origin, float Radius, FVector& OutLocation);
};
