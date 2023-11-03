// Fill out your copyright notice in the Description page of Project Settings.


#include "EntIdle.h"
#include "NavigationSystem.h"
#include "TimerManager.h"

void UEntIdle::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Idle"));

	EntRef = Cast<AEntClass>(stateOwner);

	//Basically invoke repeating
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_UpdateDestination, this, &UEntIdle::MoveToPoint, IdleIntervall, true);
}

void UEntIdle::OnExitState()
{
	//sluta invoka
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_UpdateDestination);
}

void UEntIdle::TickState()
{
}

void UEntIdle::MoveToPoint()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("moving time"));

	FVector NewDestination;
	if (GetRandomPoint(EntRef->GetActorLocation(), RandomPointRadius, NewDestination))
	{
		EntRef->MoveToRandomPoint(NewDestination);
	}
}

bool UEntIdle::GetRandomPoint(const FVector& Origin, float Radius, FVector& OutLocation)
{
	UNavigationSystemV1* NavSystem = FNavigationSystem::GetCurrent<UNavigationSystemV1>(EntRef);
		if (NavSystem)
		{
			FNavLocation RandomTargetLocation;
			if (NavSystem->GetRandomReachablePointInRadius(Origin, Radius, RandomTargetLocation))
			{
				OutLocation = RandomTargetLocation.Location;
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("found location"));

				return true;
			}
		}
	return false;
}