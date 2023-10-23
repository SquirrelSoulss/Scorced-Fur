// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlant/MovingPlantClass.h"
#include "Perception\PawnSensingComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "MovingPlant/MovingIdleState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include <Kismet/KismetMathLibrary.h>

void AMovingPlantClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlantClass::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	pawnSenser->OnSeePawn.AddDynamic(this, &AMovingPlantClass::SensedPlayer);
}

void AMovingPlantClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
 // initilialise
AMovingPlantClass::AMovingPlantClass()
{
	aggroSphere = CreateDefaultSubobject<USphereComponent>(TEXT("aggroSphere"));
	aggroSphere->InitSphereRadius(250.f);
	aggroSphere->SetupAttachment(RootComponent);

	patrolArea = CreateDefaultSubobject<UBoxComponent>(TEXT("Patrol Area"));
	//patrolArea->InitBoxExtent(FVector(50, 50, 50));

}

void AMovingPlantClass::PlayerOverlapp(APlayerCharacter* player)
{
	if(mainCharacter == nullptr)
		mainCharacter = player;
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Innercircle"));
	//stateManager->PlayerOverlapped();
}

void AMovingPlantClass::SensedPlayer(APawn* player)
{
	
	if (stateManager->CurrentState->IsA(UMovingIdleState::StaticClass())) {
		stateManager->SwitchStateByKey("sus"); // ändra, ska nog göra 
	}
}

//FVector AMovingPlantClass::GetPatrolPoint(FVector patrolPoint)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Called It"));// error invalid state
//	return patrolPoint;
//}


