// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Planner/GOAPPlanner.h"

// Sets default values for this component's properties
UGOAPPlanner::UGOAPPlanner()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGOAPPlanner::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGOAPPlanner::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

TArray<UGOAPAction*> UGOAPPlanner::Plan(AActor* agent, TSet<UGOAPAction*> availableActions, TMap<FString, bool> worldState, TMap<FString, bool> goal)
{
	for (UGOAPAction* Action : availableActions) {
		Action->DoReset();
	}

	if (useableActions.Num() != 0)
		useableActions.Empty();

	for (UGOAPAction* Action : availableActions) {
		if (Action->CheckProceduralPreconditions(agent)) {
			useableActions.Add(Action);
		}
	}

	TArray<UGOAPNode*> leaves;

	UGOAPNode* start = NewObject<UGOAPNode>();
	start->InitializeFields(NULL, 0, worldState, NULL);

	bool success = BuildGraph(start, leaves, useableActions, goal);

	if (!success) {
		//no plan
	}
	UGOAPNode* cheapest = nullptr;
	for (UGOAPNode* leaf : leaves) {
		if (cheapest == nullptr) {
			cheapest = leaf;
		}
		else {
			if (leaf->runningCost < cheapest->runningCost) {
				cheapest = leaf;
			}
		}
	}

	TArray<UGOAPAction*> result;
	UGOAPNode* n = cheapest;
	while (n != nullptr) {
		if (n->action != NULL) {
			result.Insert(n->action, 0);
		}
	}
	
	return result;
}

bool UGOAPPlanner::BuildGraph(UGOAPNode* parent, TArray<UGOAPNode*> leaves, TSet<UGOAPAction*> useableActionsC, TMap<FString, bool> goal)
{
	bool foundOne = false;
	for (UGOAPAction* action : useableActionsC) {
		if (InState(action->GetPreconditions(), parent->state)) {
			TMap<FString, bool> currentState = PopulateState(parent->state, action->GetEffects());
			UGOAPNode* node = NewObject<UGOAPNode>();
			node->InitializeFields(parent, parent->runningCost + action->cost, currentState, action);

			if (InState(goal, currentState)) {
				leaves.Add(node);
				foundOne = true;
			}
			else {
				TSet<UGOAPAction*> sub = ActionSubset(useableActionsC, action);
				bool found = BuildGraph(node, leaves, sub, goal);
				if (found)
					foundOne = true;
			}
		}
	}
	return false;
}

bool UGOAPPlanner::InState(TMap<FString, bool> test, TMap<FString, bool> testedAgainst)
{
	bool allMatch = true;
	for (const auto& testKeyValue : test) {

		bool match = false;

		for (const auto& testedAgainstKeyValue : testedAgainst) {
			if (testKeyValue == testedAgainstKeyValue) {
				match = true;
				break;
			}
		}
		if (!match) {
			allMatch = false;
		}
	}
	return allMatch;
}

TSet<UGOAPAction*> UGOAPPlanner::ActionSubset(TSet<UGOAPAction*> actions, UGOAPAction* removeMe)
{
	subSet.Empty();
	for (UGOAPAction* action : actions) {
		if (action != removeMe) {
			subSet.Add(action);
		}
	}
	return subSet;
}

TMap<FString, bool> UGOAPPlanner::PopulateState(TMap<FString, bool> currentState, TMap<FString, bool> stateChange)
{
	TMap<FString, bool> state;
	for (auto& states : currentState) {
		state.Add(states); // kanske behöveer specificiera typ tSet eller ngt tror inte det
	}

	for (auto& change : stateChange) {
		bool exists = false;

		for (auto& s : state) {
			if (s == change) {
				exists = true;
				break;
			}
		}
		if (exists) {
			state.Remove(change.Key);
			state.Add(change.Key, change.Value);
		}
		else {
			state.Add(change.Key, change.Value);
		}
	}
	return state;
}

