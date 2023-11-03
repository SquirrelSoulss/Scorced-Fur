// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IDamageRecievers.h"
#include "EnemyBaseClass.generated.h"


UCLASS()
class SQUIRRELSOULS_API AEnemyBaseClass : public ACharacter//, public IIDamageRecievers
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StateMachine")
	class UStateManagerComponent* stateManager;
	UPROPERTY(EditAnywhere, Category = "AI")
	class UPawnSensingComponent* pawnSenser;
	UPROPERTY(EditAnywhere, Category = "Life")
	float health = 30;
	UPROPERTY(BlueprintReadOnly, Category = "Life")
	bool dead = false ;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool shouldTrack = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlantMovement")
	float maxMovementSpeed = 600.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlantMovement")
	float walkSpeed = 300.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlantMovement")
	float aturnSpeed = 2.f;
	

public:
	// Sets default values for this character's properties
	AEnemyBaseClass(); 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool sensesPlayer = false;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "MainCharacter") // switch to the class that is the main character
	AActor* mainCharacter = nullptr;
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SensedPlayer")
	void PlayerSpotted();
	virtual void PlayerSpotted_Implementation();
	//virtual void TakeDamage_Implementation(float damageTaken) override;
	
	FRotator FixRotation(FVector actorLocation, FVector targetLocation, float deltaTime, float turnSpeed = 2.f);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	virtual void OnSeePawn(APawn* player);
};
