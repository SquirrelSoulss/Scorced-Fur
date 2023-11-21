// Fill out your copyright notice in the Description page of Project Settings.


#include "StationaryPlantClass.h"
#include "StateManagerComponent.h"
#include "Perception\PawnSensingComponent.h"
#include "PlantIdle.h"
#include <Kismet/KismetMathLibrary.h>
#include "Components/ArrowComponent.h"
#include "Engine/EngineTypes.h"
#include "SquirrelSouls/PlayerCharacter.h"


void AStationaryPlantClass::BeginPlay()
{
	AEnemyBaseClass::BeginPlay();
	ShootRef->AttachToComponent(GetMesh(), FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("Head"));
}

void AStationaryPlantClass::PostInitializeComponents()
{
	AEnemyBaseClass::PostInitializeComponents();

	pawnSenser->OnSeePawn.AddDynamic(this, &AStationaryPlantClass::OnSePawn);
}

AStationaryPlantClass::AStationaryPlantClass()
{
	ShootRef = CreateDefaultSubobject<UArrowComponent>(TEXT("ShootRef"));
	ShootRef->SetupAttachment(GetMesh(), TEXT("Jaw1"));
}

void AStationaryPlantClass::PlayerSpotted_Implementation()
{
	AEnemyBaseClass::PlayerSpotted_Implementation();
}

void AStationaryPlantClass::Tick(float DeltaTime)
{
	AEnemyBaseClass::Tick(DeltaTime);
	if ( mainCharacter != nullptr && shouldTrack) 
	{
		FRotator targetRot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), mainCharacter->GetActorLocation());
		FRotator newRotation = FMath::RInterpTo(targetBoneRotation,targetRot, DeltaTime, aturnSpeed); // can change speed in order to speed up tracking during attacks
		targetBoneRotation = FRotator(0,newRotation.Yaw,0); //targetBoneRotation = newRotation;
	}

}

void AStationaryPlantClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	AEnemyBaseClass::SetupPlayerInputComponent(PlayerInputComponent);
}

void AStationaryPlantClass::OnSePawn(APawn* player)
{
	APawn* Player = Cast<APawn>(player); //should cast to the main character blueprint
	{
		if (Player == nullptr)
			return;
	}
	if(mainCharacter == nullptr && Cast<APlayerCharacter>(player) != NULL)
		mainCharacter = player;

	if (stateManager->CurrentState->IsA(UPlantIdle::StaticClass())) {
		stateManager->SwitchStateByKey("Suspicious");
	}
		
}

void AStationaryPlantClass::TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource)
{
	stateManager->CurrentState->Damaged(Damage);
}

void AStationaryPlantClass::ShootProjectile()
{
	
	APlantProjectile* p = this->GetWorld()->SpawnActor<APlantProjectile>(this->ProjectileClass, ShootRef->GetComponentTransform());
	if (!ShootRef->GetComponentTransform().IsValid()) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Null ref"));

	}
	if (p == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Null thingy"));

		return;
	}
	if (mainCharacter == nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Null MC"));

		return;
	}
	FVector dir = mainCharacter->GetActorLocation() - GetActorLocation();
	p->FireInDirection(dir.GetSafeNormal());
	//mmaybe change this to a object pool type of thing
}


