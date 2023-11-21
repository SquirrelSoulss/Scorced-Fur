// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GOAP/Labourer.h"
#include "Merchant.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API AMerchant : public ALabourer
{
	GENERATED_BODY()
public:

	virtual TMap<FString, bool> GetWorldState() override;
	virtual TMap<FString, bool> CreateGoalState() override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
