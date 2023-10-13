// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseClass.h"
#include "StationaryPlantClass.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API AStationaryPlantClass : public AEnemyBaseClass
{
	GENERATED_BODY()

public:
	
	virtual void PlayerSpotted_Implementation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges") //move to StationaryPlantplantClass
		FRotator targetBoneRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	virtual void OnSePawn(APawn* player) ;
};
