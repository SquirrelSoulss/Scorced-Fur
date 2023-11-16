// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "MathFunctions.h"
#include "AIController.h"
#include "IEntObserver.h"
#include "EntAggro.generated.h"

/**
 *
 */

UCLASS()
class SQUIRRELSOULS_API UEntAggro : public UEntStateBase, public IIEntObserver
{
	GENERATED_BODY()

private:
	MathFunctions MathStuffRef;

public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState() override;

	UPROPERTY()
	TEnumAsByte<ECollisionChannel> traceChannel = ECC_Pawn;
	FCollisionQueryParams queryParams;

	FTimerHandle TimerHandle_ChooseAttack;

	AAIController* EntAIController = nullptr;

	UFUNCTION()
	void InitializeAttackArray();
	void ChooseAttack();
	float GetDistance();
	FEntAttackTypeData ChooseAttackLogic(float distance);

	virtual void NotifyPlayerTooClose_Implementation() override;
};
