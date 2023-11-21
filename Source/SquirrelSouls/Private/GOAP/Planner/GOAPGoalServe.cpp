// Fill out your copyright notice in the Description page of Project Settings.


#include "GOAP/Planner/GOAPGoalServe.h"
#include "GOAP/Labourer.h"

float UGOAPGoalServe::GetPriority()
{
	ALabourer* dp = Cast<ALabourer>(dataProvider);
	priority = 1;
	if (dp != nullptr)
	{
		statesMap = dp->GetWorldState();
		if (statesMap.Contains("customerWaiting")) {
			if (statesMap["customerWaiting"] == true) {
				priority = 100;
			}
		}
	}

	return priority;
}
