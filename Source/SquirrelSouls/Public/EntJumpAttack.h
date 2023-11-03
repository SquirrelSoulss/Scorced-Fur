// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EntStateBase.h"
#include "EntJumpAttack.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UEntJumpAttack : public UEntStateBase
{
	GENERATED_BODY()
	
public:
	virtual void OnEnterState(AActor* stateOwner) override;
	virtual void OnExitState() override;
	virtual void TickState(float DeltaTime) override;


};
