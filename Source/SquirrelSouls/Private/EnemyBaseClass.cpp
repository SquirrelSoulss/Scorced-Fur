// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBaseClass.h"
#include "Perception\PawnSensingComponent.h"
#include "StateManagerComponent.h"

// Sets default values
AEnemyBaseClass::AEnemyBaseClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("State Manager"));
	pawnSenser = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("Pawn Senser"));
}
//kind of like awake?
void AEnemyBaseClass::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//C:\Program Files\Epic Games\UE_5.3\Engine\Source\Runtime\AIModule\Classes\Perception\PawnSensingComponent.h 
}
// Called when the game starts or when spawned
void AEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyBaseClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyBaseClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyBaseClass::OnSeePawn(APawn* player)
{

	
}


