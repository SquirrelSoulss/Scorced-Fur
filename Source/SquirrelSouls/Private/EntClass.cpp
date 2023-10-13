// Fill out your copyright notice in the Description page of Project Settings.


#include "EntClass.h"

// Sets default values
AEntClass::AEntClass()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AEntClass::StartFight()
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

