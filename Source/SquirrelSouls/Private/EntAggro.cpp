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

	//EntRef->MoveToPlayer();

	ChilloutPeriod = EntRef->ChilloutPeriod;

	InitializeAttackArray();
	GetWorld()->GetTimerManager().SetTimer(TimerHandle_ChooseAttack, this, &UEntAggro::ChooseAttack, ChilloutPeriod, true);
}

void UEntAggro::OnExitState()
{
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle_ChooseAttack);
}

void UEntAggro::TickState(float DeltaTime)
{
	Super::TickState(DeltaTime);

	if (!IsAttacking)
		RotateToPlayer(DeltaTime);
}

void UEntAggro::RotateToPlayer(float DeltaTime)
{
	
	FVector PlayerPos = PlayerRef->GetActorLocation();
	FVector EntPos = EntRef->GetActorLocation();

	//FVector NewPos = FMath::VInterpTo(EntPos, PlayerPos, DeltaTime, MovementSpeed);
	//EntRef->SetActorLocation(NewPos);

	FVector DirToPlayer = (PlayerPos - EntPos).GetSafeNormal();
	FRotator RotToPlayer = DirToPlayer.Rotation();

	FRotator CurrentRot = EntRef->GetActorRotation();
	FRotator NewRot = FMath::RInterpTo(CurrentRot, RotToPlayer, DeltaTime, RotationSpeed);

}

void UEntAggro::InitializeAttackArray()
{
	//Add attacks here
	AvailableAttacks.Add({ "HandAttack", 500.f, 0.75f });
	AvailableAttacks.Add({ "StompAttack", 350.f, 0.75f });
	AvailableAttacks.Add({ "JumpAttack", 800.f, 0.3f });
}

void UEntAggro::ChooseAttack()
{
	if (EntRef && PlayerRef && !EntRef->IsAttacking)
	{
		float PlayerDistance = GetDistance();

		FEntAttackTypeData ChosenAttack = ChooseAttackLogic(PlayerDistance);

		if (ChosenAttack.StateName.IsEmpty())
			IsAttacking = false;

		else
		{
			IsAttacking = true;
			EntRef->SwitchState(ChosenAttack.StateName);
		}
	}
}

float UEntAggro::GetDistance()
{
	FHitResult hit;

	EntRef->GetWorld()->LineTraceSingleByChannel(hit, EntRef->GetActorLocation(), PlayerRef->GetActorLocation(), traceChannel, queryParams);
	DrawDebugLine(EntRef->GetWorld(), EntRef->GetActorLocation(), PlayerRef->GetActorLocation(), FColor::Red);

	return hit.Distance;
}

FEntAttackTypeData UEntAggro::ChooseAttackLogic(float distance)
{
	//Debug set attack
	//return AvailableAttacks[2];

	TArray<FEntAttackTypeData> ValidAttacks;

	for (const FEntAttackTypeData& AttackData : AvailableAttacks)
	{
		if (distance <= AttackData.AttackRange)
		{
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
	else
	{
		if (MathStuffRef.RandomBoolWithWeight(0.1f))
		{
			int RandomAttackIndex = FMath::FRandRange(0.f, AvailableAttacks.Num());
			return AvailableAttacks[RandomAttackIndex];
		}
	}

	return FEntAttackTypeData();
}



