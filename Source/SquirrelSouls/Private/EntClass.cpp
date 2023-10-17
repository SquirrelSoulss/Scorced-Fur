// Fill out your copyright notice in the Description page of Project Settings.


#include "EntClass.h"
#include "EntIdle.h"
#include "EntAggro.h"
#include "StateManagerComponent.h"

// Sets default values
AEntClass::AEntClass()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("State Manager"));
}

void AEntClass::StartFight_Implementation(APawn* _player)
{
	AActor* player = Cast<AActor>(_player);

	if (player == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("playyer is null"));
		return;
	}		
	playerRef = player;

	SetUpFight();
	this->stateManager->SwitchStateByKey("Aggro");
}

void AEntClass::SetUpFight_Implementation()
{
}

void AEntClass::MoveToPlayer_Implementation()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("moving to player"));

}

void AEntClass::MoveToRandomPoint_Implementation(FVector destination)
{
}

// Called when the game starts or when spawned
void AEntClass::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEntClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEntClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


