// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseClass.h"
#include "SquirrelSouls/PlayerCharacter.h"
#include "MovingPlantClass.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API AMovingPlantClass : public AEnemyBaseClass
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	UPROPERTY(EditAnywhere, Category = "PawnSense")
	class USphereComponent* aggroSphere;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AIMove")
	class UBoxComponent* patrolArea;
	virtual void Tick(float DeltaTime) override;
	AMovingPlantClass();
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "Bool changes")
	bool attackTrigger = false;
	UFUNCTION(BlueprintImplementableEvent, Category = "Patrol")
	void CallGetPatrolPoint();
	UFUNCTION(BlueprintCallable, Category = "AggroSphere")
	void PlayerOverlapp(APlayerCharacter* player);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Patrol")
	FVector randomPoint;
	UFUNCTION()
	void SensedPlayer(APawn* player);
	UFUNCTION(BlueprintCallable, Category = "Patrol")
	FVector GetPatrolPoint(FVector patrolPoint);

	void ChangeMovementSpeed(float speed);
};
