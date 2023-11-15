// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Actions/GOAPAction.h"

UGOAPAction::UGOAPAction() {
	
}

void UGOAPAction::SetAgent(ACharacter* usedAgent)
{
	myAgent = usedAgent;
}

void UGOAPAction::DoReset()
{
	inRange = false;
	target = nullptr;
}

void UGOAPAction::Reset()
{
}

bool UGOAPAction::IsDone()
{
	return false;
}

bool UGOAPAction::CheckProceduralPreconditions(AActor* agent)
{
	return true;
}

bool UGOAPAction::Perform()
{
	return false;
}

bool UGOAPAction::RequiresInRange()
{
	return false;
}

bool UGOAPAction::IsInRange()
{
	return inRange;
}

void UGOAPAction::AddPrecondition(FString key, bool value)
{
	preconditions.Add(key,value);
}

//Will crash if no such key was found.
void UGOAPAction::RemovePrecondition(FString key)
{
	preconditions.FindAndRemoveChecked(key); 
}

void UGOAPAction::AddEffect(FString key, bool value)
{
	effects.Add(key, value);
}

//Will crash if no such key is found.
void UGOAPAction::RemoveEffect(FString key)
{
	effects.FindAndRemoveChecked(key);
}

TMap<FString, bool> UGOAPAction::GetPreconditions()
{
	return preconditions;
}

TMap<FString, bool> UGOAPAction::GetEffects()
{
	return effects;
}
