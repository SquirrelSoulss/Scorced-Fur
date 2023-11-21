// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IDamageRecievers.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

UCLASS()
class SQUIRRELSOULS_API APlayerCharacter : public ACharacter, public IIDamageRecievers
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	UFUNCTION(BlueprintNativeEvent, Category="Potion")
	void GetHealthPotions(int32 amount);
	virtual void GetHealthPotions_Implementation(int32 amount);
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void TakeDamage_Implementation(float DamageTaken, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource);

};
