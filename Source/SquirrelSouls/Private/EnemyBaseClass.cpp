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
	pawnSenser->OnSeePawn.AddDynamic(this, &AEnemyBaseClass::OnSeePawn);
}
// Called when the game starts or when spawned
void AEnemyBaseClass::BeginPlay()
{
	Super::BeginPlay();
	PlayerSpotted_Implementation();
	PlayerSpotted();
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
	APawn* Player = Cast<APawn>(player); 
	{
		if (Player == nullptr)
			return;
	}
	
}

void AEnemyBaseClass::PlayerSpotted_Implementation()
{
	
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("poop"));
}


