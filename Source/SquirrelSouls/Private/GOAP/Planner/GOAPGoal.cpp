// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Planner/GOAPGoal.h"

float UGOAPGoal::GetPriority()
{
	return priority;
}

void UGOAPGoal::SetDataProvider(ACharacter* actor)
{
	dataProvider = actor;
}


