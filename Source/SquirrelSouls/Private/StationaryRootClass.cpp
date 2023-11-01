// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryRootClass.h"

// Sets default values
AStationaryRootClass::AStationaryRootClass()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStationaryRootClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStationaryRootClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStationaryRootClass::NormalAttack_Implementation()
{
}

