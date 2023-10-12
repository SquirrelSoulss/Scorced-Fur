// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyBaseClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API AEnemyBaseClass : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "StateMachine")
	class UStateManagerComponent* stateManager;
	UPROPERTY(EditAnywhere, Category = "AI")
	class UPawnSensingComponent* pawnSenser;


	
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
	void OnSeePawn(APawn* player);
};
