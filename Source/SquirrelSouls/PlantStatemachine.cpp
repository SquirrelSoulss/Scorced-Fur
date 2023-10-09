// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantStatemachine.h"

// Sets default values
APlantStatemachine::APlantStatemachine()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlantStatemachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlantStatemachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlantStatemachine::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

