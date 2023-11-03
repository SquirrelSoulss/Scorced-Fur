// Fill out your copyright notice in the Description page of Project Settings.


#include "EntJumpAttack.h"
#include "Kismet/KismetMathLibrary.h"

void UEntJumpAttack::OnEnterState(AActor* stateOwner)
{
	Super::OnEnterState(stateOwner);

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Jump"));

	EntRef->StartJumpAttack();
}

void UEntJumpAttack::OnExitState()
{
}

void UEntJumpAttack::TickState(float DeltaTime)
{
	Super::TickState(DeltaTime);
}


