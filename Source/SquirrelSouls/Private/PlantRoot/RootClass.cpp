// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantRoot/RootClass.h"
#include "StateManagerComponent.h"
#include "AIController.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARootClass::ARootClass()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("State Manager"));
}

// Called when the game starts or when spawned
void ARootClass::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	//Find skeletal mesh and get the ABP class
	AnimRef = Cast<URootAnimInstance>(FindComponentByClass<USkeletalMeshComponent>()->GetAnimInstance());
	if (!AnimRef)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("anim is null"));
}

// Called every frame
void ARootClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARootClass::CheckIfHit_Implementation()
{
}

void ARootClass::UpdateHealthBar_Implementation(float currentHealth)
{
}

void ARootClass::PlayerInRadius()
{
	bool IsNormal = FMath::RandBool();

	if (IsNormal)
		SwitchState("Normal");
	else
		SwitchState("Swipe");
}

void ARootClass::SwitchState(FString key)
{
	stateManager->SwitchStateByKey(key);
}

void ARootClass::DoDamageToPlayer(float Damage)
{
}

void ARootClass::TakeDamage_Implementation(float damage)
{
	Health -= damage;
	Health = FMath::Clamp(Health, 0, MaxHealth);

	UpdateHealthBar(damage);
}