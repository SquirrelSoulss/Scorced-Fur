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

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MoveTo")
	void MoveToPoint(FVector point);
	virtual	void MoveToPoint_Implementation(FVector point);
};
