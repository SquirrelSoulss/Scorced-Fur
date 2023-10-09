// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStateManagerComponent.h"

// Sets default values
APlantStateManagerComponent::APlantStateManagerComponent()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlantStateManagerComponent::BeginPlay()
{
	Super::BeginPlay();
	InitializeStates();
	InitStateManager();
	
}

// Called every frame
void APlantStateManagerComponent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bCanTickState == true)
	{
		CurrentState->TickState();
	}

}

void APlantStateManagerComponent::SwitchStateByKey(FString StateKey)
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

void APlantStateManagerComponent::SwitchState(UPlantStateBase* NewState)
{

}

void APlantStateManagerComponent::InitStateManager()
{
	SwitchStateByKey(InitialState);
}

void APlantStateManagerComponent::InitializeStates()
{
	for (auto It = AvailableStates.CreateConstIterator(); It; ++It)
	{
		UPlantStateBase* State = NewObject<UPlantStateBase>(this, It->Value);
		StateMap.Add(It->Key, State);
	}
}

