// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "MathFunctions.h"
#include "EntAggro.generated.h"

/**
 *
 */
USTRUCT(BlueprintType)
struct FEntAttackTypeData
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StateName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Weight;
};

UCLASS()
class SQUIRRELSOULS_API UEntAggro : public UEntStateBase
{
	GENERATED_BODY()

private:
	MathFunctions MathStuffRef;

public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;

	UPROPERTY()
	TEnumAsByte<ECollisionChannel> traceChannel = ECC_Pawn;
	FCollisionQueryParams queryParams;

	FTimerHandle TimerHandle_ChooseAttack;
	float ChilloutPeriod;
	bool IsAttacking;
	float RotationSpeed = 2.f;
	float MovementSpeed = 50.f;


	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FEntAttackTypeData> AvailableAttacks;

	UFUNCTION()
	void InitializeAttackArray();
	void ChooseAttack();
	float GetDistance();
	FEntAttackTypeData ChooseAttackLogic(float distance);
};
