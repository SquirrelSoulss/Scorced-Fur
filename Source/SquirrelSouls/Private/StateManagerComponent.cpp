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
		CurrentState->TickState();
	}
	// ...
}

void UStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	UStateBase* NewState = StateMap.FindRef(StateKey);
	if (NewState->IsValidLowLevel())
	{
		if (!CurrentState)
		{
			CurrentState = NewState;
		}
		else
		{
			if (CurrentState->GetClass() == NewState->GetClass() && CurrentState->bCanRepeatState == false)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("RepeatState not true in Blueprint"));// error invalid state
				return;
			}
			else
			{
				bCanTickState = false;
				CurrentState->OnExitState();

				if (shouldTrackStateHistory == true) 
				{
					if (StateHistory.Num() < StateHistoryLenght)
					{
						StateHistory.Push(CurrentState);
					}
					else
					{
						StateHistory.RemoveAt(0);
						StateHistory.Push(CurrentState);
					}
				}
				CurrentState = NewState;
			}
		}

		if (CurrentState)
		{

			CurrentState->OnEnterState(GetOwner());
			bCanTickState = true;
		}
		else
		{
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

void UStateManagerComponent::InitializeStates()
{
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Added THings"));
		UStateBase* State = NewObject<UStateBase>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}

