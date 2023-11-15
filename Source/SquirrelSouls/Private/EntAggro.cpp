// Fill out your copyright notice in the Description page of Project Settings.


#include "EntAggro.h"
#include "Kismet/KismetMathLibrary.h"
#include "TimerManager.h"
#include "MathFunctions.h"
#include "NavigationSystem.h"
#include "AIController.h"
#include "Misc/App.h"

void UEntAggro::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	bCanTickState = true;

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Aggro"));

	queryParams.AddIgnoredActor(EntRef);

	if (EntRef->AvailableAttacks.Num() <= 0)
		InitializeAttackArray();

	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ChooseAttack, this, &UEntAggro::ChooseAttack, EntRef->ChilloutPeriod, true);

	if (!EntAIController)
	{
		EntAIController = Cast<AAIController>(EntRef->Controller);
	}
	EntRef->CanMove = true;
	EntAIController->MoveToActor(PlayerRef, 350.f);
}

void UEntAggro::OnExitState()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ChooseAttack);
	EntAIController->StopMovement();
}

void UEntAggro::TickState()
{
}

void UEntAggro::InitializeAttackArray()
{
	//Add attacks here

	EntRef->AvailableAttacks.Add({ "None", 1500.f, 0.05f });
	EntRef->AvailableAttacks.Add({ "HandAttack", 350.f, 0.4f });
	EntRef->AvailableAttacks.Add({ "StompAttack", 400.f, 0.35f });
	EntRef->AvailableAttacks.Add({ "JumpAttack", 1500.f, 0.1f });
	//EntRef->AvailableAttacks.Add({ "ComboAttack", 500.f, 0.8f });

	FAvailableCombos newCombo;
	newCombo.isFire = false;

	newCombo.ComboArray = { "HandAttack", "HandAttack", "StompAttack" };
	EntRef->AvailableCombos.Add(newCombo);

	newCombo.ComboArray = { "HandAttack", "StompAttack", "StompAttack" };
	EntRef->AvailableCombos.Add(newCombo);

	newCombo.ComboArray = { "StompAttack", "HandAttack" };
	EntRef->AvailableCombos.Add(newCombo);
}

void UEntAggro::ChooseAttack()
{
	if (!EntRef->IsAttacking)
	{
		float PlayerDistance = GetDistance();

		FEntAttackTypeData ChosenAttack = ChooseAttackLogic(PlayerDistance);

		if (ChosenAttack.StateName != "None")
		{
			EntRef->SwitchState(ChosenAttack.StateName);
			EntAIController->StopMovement();
		}
		else
		{
			EntAIController->MoveToActor(PlayerRef, 350.f);
		}
	}
}

float UEntAggro::GetDistance()
{
	FHitResult hit;

	EntRef->GetWorld()->LineTraceSingleByChannel(hit, EntRef->GetActorLocation(), PlayerRef->GetActorLocation(), traceChannel, queryParams);

	return hit.Distance;
}

FEntAttackTypeData UEntAggro::ChooseAttackLogic(float distance)
{
	//Debug set attack
	//return EntRef->AvailableAttacks[4];

	TArray<FEntAttackTypeData> ValidAttacks;

	for (const FEntAttackTypeData& AttackData : EntRef->AvailableAttacks)
	{
		if (distance <= AttackData.AttackRange)
		{
			if (AttackData.StateName == "SpawnAttack" && !EntRef->CanSpawn)
				continue;
			else
				ValidAttacks.Add(AttackData);
		}
	}

	if (ValidAttacks.Num() > 0)
	{
		float TotalWeight = 0.f;
		for (const FEntAttackTypeData& AttackData : ValidAttacks)
		{
			TotalWeight += AttackData.Weight;
		}

		float RandomValue = FMath::FRand() * TotalWeight;

		for (const FEntAttackTypeData& AttackData : ValidAttacks)
		{
			RandomValue -= AttackData.Weight;
			if (RandomValue < 0.f)
			{
				return AttackData;
			}
		}
	}

	return EntRef->AvailableAttacks[0];
}



