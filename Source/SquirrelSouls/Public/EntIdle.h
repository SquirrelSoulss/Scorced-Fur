// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntIdle.generated.h"

/**
 *
 */
UCLASS()
class SQUIRRELSOULS_API UEntIdle : public UEntStateBase
{
	GENERATED_BODY()

public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;

private:
	FVector CurrentLocation;
	AEntClass* entRef;

	FTimerHandle TimerHandle_UpdateDestination;

public:
	UPROPERTY(EditAnywhere)
	float RandomPointRadius = 1000.f;
	
	UPROPERTY(EditAnywhere)
	float IdleIntervall = 10.f;

	UFUNCTION()
	void MoveToPoint();
	bool GetRandomPoint(const FVector& Origin, float Radius, FVector& OutLocation);
};
