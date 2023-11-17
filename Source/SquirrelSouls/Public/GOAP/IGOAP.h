// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Actions/GOAPAction.h" 
#include "IGOAP.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIGOAP : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SQUIRRELSOULS_API IIGOAP
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	TMap<FString, bool> GetWorldState();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	TMap<FString, bool> CreateGoalState();
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	virtual void PlanFailed(TMap<FString, bool> failedGoal);
	//UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	virtual void PlanFound(TMap<FString, bool> goal, TArray<UGOAPAction*> actions);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	void ActionsFinished();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	void PlanAborted(UGOAPAction* aborter);
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "GOAP")
	bool MoveAgent(UGOAPAction* nextAction);
	
};
