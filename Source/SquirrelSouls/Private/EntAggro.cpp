// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAggro.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"

void UEntAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	bCanTickState = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Aggro"));

	queryParams.AddIgnoredActor(EntRef);

	EntRef->MoveToPlayer();

	ChilloutPeriod = EntRef->ChilloutPeriod;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ChooseAttack, this, &UEntAggro::ChooseAttack, ChilloutPeriod, false);
}

void UEntAggro::OnExitState()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ChooseAttack);

}

void UEntAggro::TickState()
{


}

void UEntAggro::ChooseAttack()
{
	if (EntRef && playerRef && !EntRef->IsAttacking)
	{
		GetAttack(GetDistance());
	}
}

void UEntAggro::DoAttack(FString AttackToDo)
{
	EntRef->SwitchState(AttackToDo);
}

float UEntAggro::GetDistance()
{
	FHitResult hit;

	EntRef->GetWorld()->LineTraceSingleByChannel(hit, EntRef->GetActorLocation(), playerRef->GetActorLocation(), traceChannel, queryParams);
	DrawDebugLine(EntRef->GetWorld(), EntRef->GetActorLocation(), playerRef->GetActorLocation(), FColor::Red);

	float distance = hit.Distance;

	return distance;
}



