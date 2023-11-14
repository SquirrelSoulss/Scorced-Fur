// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SquirrelSouls/Public/GOAP/Actions/GOAPAction.h"
#include "Containers/Queue.h"
#include "GOAPNode.h"
#include "GOAPPlanner.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SQUIRRELSOULS_API UGOAPPlanner : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGOAPPlanner();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	TArray<UGOAPAction*> Plan(AActor* agent, TSet<UGOAPAction*> availableActions, TMap<FString, bool> worldState, TMap<FString, bool> goal);
	TSet<UGOAPAction*> useableActions;

private:
	bool BuildGraph(UGOAPNode* parent, TArray<UGOAPNode*> leaves, TSet<UGOAPAction*> useableActionsC, TMap<FString, bool> goal);
	bool InState(TMap<FString, bool> test, TMap<FString, bool> testedAgainst);
	TSet<UGOAPAction*> ActionSubset(TSet<UGOAPAction*> actions, UGOAPAction* removeMe);
	TMap<FString, bool> PopulateState(TMap<FString, bool> currentState, TMap<FString, bool> stateChange);
	TSet<UGOAPAction*> subSet;
};


