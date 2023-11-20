// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManagerComponent.h"

// Sets default values for this component's properties
UStateManagerComponent::UStateManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeStates();
	InitStateManager();
	// ...
	
}


// Called every frame
void UStateManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bCanTickState == true)
	{

		CurrentState->TickState(); // provides tick/update to the states that uses it
	}
	// ...
}

void UStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	UStateBase* NewState = StateMap.FindRef(StateKey); //stateMap is the holder of all states
	if (NewState->IsValidLowLevel()) 
	{
		if (!CurrentState)
		{
			CurrentState = NewState;
		}
		else
		{
			if (CurrentState->GetClass() == NewState->GetClass() && CurrentState->bCanRepeatState == false) // if the state we entered is the same as current state, check if it can enter itself
			{
				return;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("cant enter again"));
			}
			else
			{
				bCanTickState = false;
				CurrentState->OnExitState(); // exit the state
				if (shouldTrackStateHistory == true)
				{
					if (StateHistory.Num() < StateHistoryLenght)
					{
						StateHistory.Insert(CurrentState,0);
					}
					else
					{
						StateHistory.RemoveAt(StateHistoryLenght-1);
						StateHistory.Insert(CurrentState,0);
					}
				}
				CurrentState = NewState; // set the new state
			}
		}

		if (CurrentState)
		{

			CurrentState->OnEnterState(GetOwner()); // enter the new state
			bCanTickState = true;
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Invalid state added in Available states"));// error invalid state
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Invalid state added in Available states"));// error invalid state
		}
	}
}

void UStateManagerComponent::SwitchState(UStateBase* NewState)
{
}

void UStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void UStateManagerComponent::PlayerOverlapped()
{
	CurrentState->PlayerOverlapping();
}

void UStateManagerComponent::InitializeStates()
{
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Added THings"));
		UStateBase* State = NewObject<UStateBase>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}

