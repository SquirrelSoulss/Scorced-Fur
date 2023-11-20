// Fill out your copyright notice in the Description page of Project Settings.


#include "EntClass.h"
#include "EntIdle.h"
#include "EntAggro.h"
#include "StateManagerComponent.h"
#include "AIController.h"

// Sets default values
AEntClass::AEntClass()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	stateManager = CreateDefaultSubobject<UStateManagerComponent>(TEXT("State Manager"));
}

// Called when the game starts or when spawned
void AEntClass::BeginPlay()
{
	Super::BeginPlay();

	AnimRef = GetMesh()->GetAnimInstance();
	if (!AnimRef)
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("anim is null"));
}

void AEntClass::StartFight(APawn* _player)
{
	AActor* player = Cast<AActor>(_player);

	if (player == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("player is null"));
		return;
	}
	PlayerRef = player;

	this->stateManager->SwitchStateByKey("Aggro");
}

void AEntClass::SwitchState(FString StateKey)
{
	stateManager->SwitchStateByKey(StateKey);
}

void AEntClass::RotateToPlayer(float DeltaTime)
{
	if (PlayerRef == nullptr) return;

	FVector PlayerPos = PlayerRef->GetActorLocation();
	FVector EntPos = GetActorLocation();

	FVector DirToPlayer = (PlayerPos - EntPos).GetSafeNormal();
	FRotator RotToPlayer = DirToPlayer.Rotation();

	FRotator EntRot = GetActorRotation();
	FRotator NewRot = FMath::RInterpTo(EntRot, RotToPlayer, DeltaTime, RotationSpeed);

	IsRotatingInPlace = !FMath::IsNearlyEqual(NewRot.Yaw, EntRot.Yaw, 0.25f);

	SetActorRotation(FRotator(EntRot.Pitch, NewRot.Yaw, EntRot.Roll));
}

// Called every frame
void AEntClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!IsAttacking && !IsDead)
		RotateToPlayer(DeltaTime);

	else if (IsAttacking && !IsDead)
		CheckForHit();
}

// Called to bind functionality to input
void AEntClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AEntClass::TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource)
{
}

void AEntClass::NotifyPlayerTooClose_Implementation()
{
}
