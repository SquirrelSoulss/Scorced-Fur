// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlant/MovingPlantClass.h"
#include "Perception\PawnSensingComponent.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "MovingPlant/MovingIdleState.h"
#include "SquirrelSouls/Public/StateManagerComponent.h"
#include <Kismet/KismetMathLibrary.h>
#include "GameFramework/CharacterMovementComponent.h"


void AMovingPlantClass::BeginPlay()
{
	Super::BeginPlay();
}

void AMovingPlantClass::PostInitializeComponents()
{
	AEnemyBaseClass::PostInitializeComponents();
	pawnSenser->OnSeePawn.AddDynamic(this, &AMovingPlantClass::SensedPlayer);
}

void AMovingPlantClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime); 
	if (mainCharacter != nullptr && shouldTrack)
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), mainCharacter->GetActorLocation());
		FRotator newRotation = FMath::RInterpTo(GetActorRotation(), targetRot, DeltaTime, aturnSpeed); // can change speed in order to speed up tracking during attacks
		SetActorRotation(FRotator(0, newRotation.Yaw, 0)); 
	}
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
		stateManager->SwitchStateByKey("decide"); 
	}
}

FVector AMovingPlantClass::GetPatrolPoint(FVector patrolPoint)
{
	randomPoint = patrolPoint;

	return patrolPoint;
}

void AMovingPlantClass::ChangeMovementSpeed(float speed)
{
	GetCharacterMovement()->MaxWalkSpeed = speed;
}

void AMovingPlantClass::TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource)
{
	stateManager->CurrentState->Damaged(Damage);

}


