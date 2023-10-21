// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntAggro.generated.h"

/**
 *
 */
UCLASS()
class SQUIRRELSOULS_API UEntAggro : public UEntStateBase
{
	GENERATED_BODY()

public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;

	UPROPERTY()
	TEnumAsByte<ECollisionChannel> traceChannel = ECC_Pawn;
	FCollisionQueryParams queryParams;

	FTimerHandle TimerHandle_ChooseAttack;
	float ChilloutPeriod;

	UFUNCTION()
	void ChooseAttack();
	UFUNCTION(BlueprintCallable, Category = "ChooseAttack")
	void DoAttack(FString AttackToDo);
	UFUNCTION()
	float GetDistance();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "ChooseAttack")
	void GetAttack(float distance);
};
