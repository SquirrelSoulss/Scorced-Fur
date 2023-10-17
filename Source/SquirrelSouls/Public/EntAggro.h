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


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ChooseAttack")
	float inNormalRange = 400.f;
	float inStompRange = 200.f;
	float rangedRange = 800.f;

	UFUNCTION()
	void ChooseAttackP1();

};
