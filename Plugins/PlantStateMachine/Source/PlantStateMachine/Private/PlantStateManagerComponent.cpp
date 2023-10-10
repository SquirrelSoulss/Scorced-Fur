// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateManagerComponent.h"

// Sets default values
UPlantStateManagerComponent::UPlantStateManagerComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryComponentTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void UPlantStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeStates();
	InitStateManager();
	
}

// Called every frame
void UPlantStateManagerComponent::TickComponent(float DeltaTime,ELevelTick ticktype, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, ticktype, ThisTickFunction);
	if (bCanTickState == true)
	{
		CurrentState->TickState();
	}
	
}

void UPlantStateManagerComponent::SwitchStateByKey(FString StateKey)
{
	UPlantStateBase* NewState = StateMap.FindRef(StateKey);
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
				//Nope
			}
			else 
			{
				bCanTickState = false;
				CurrentState->OnExitState();
				if (StateHistory.Num() < StateHistoryLenght) 
				{
					StateHistory.Push(CurrentState);
				}
				else
				{
					StateHistory.RemoveAt(0);
					StateHistory.Push(CurrentState);
				}

				CurrentState = NewState;
			}
		}

		if (CurrentState) 
		{
			CurrentState->OnEnterState(GetOwner());
			bCanTickState = true;
		}
	}
	else
	{
		// error invalid state
	}

}

void UPlantStateManagerComponent::SwitchState(UPlantStateBase* NewState)
{

}

void UPlantStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void UPlantStateManagerComponent::InitializeStates()
{
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It)
	{
		UPlantStateBase* State = NewObject<UPlantStateBase>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}

