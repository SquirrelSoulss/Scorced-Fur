// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EntClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API AEntClass : public ACharacter
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "StateMachine")
	class UStateManagerComponent* stateManager;

public:
	// Sets default values for this character's properties
	AEntClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerRef")
	AActor* playerRef = nullptr; // change to player class later

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SensedPlayer")
	void StartFight(APawn* player);
	virtual void StartFight_Implementation(APawn* player);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SensedPlayer")
	void SetUpFight();
	virtual void SetUpFight_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "MoveToPlayer")
	void MoveToPlayer();
	virtual void MoveToPlayer_Implementation();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
