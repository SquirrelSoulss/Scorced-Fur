// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlant/MovingPlantClass.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include <Kismet/KismetMathLibrary.h>

void AMovingPlantClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlantClass::PostInitializeComponents()
{
	Super::PostInitializeComponents();
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
	stateManager->PlayerOverlapped();
}

//FVector AMovingPlantClass::GetPatrolPoint(FVector patrolPoint)
//{
//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Called It"));// error invalid state
//	return patrolPoint;
//}


