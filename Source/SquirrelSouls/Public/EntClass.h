// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IDamageRecievers.h"
#include "EntClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API AEntClass : public ACharacter, public IIDamageRecievers
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "StateMachine")
	class UStateManagerComponent* stateManager;

public:
	// Sets default values for this character's properties
	AEntClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	AActor* PlayerRef = nullptr; // change to player class later

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	UAnimInstance* AnimRef = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckForHit")
	bool IsAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool CanMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool CanSpawn = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool IsRotatingInPlace = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool IsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool IsFireDamage = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	float ChilloutPeriod = 2.f;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "SensedPlayer")
	void StartFight(APawn* player);
	virtual void StartFight_Implementation(APawn* player);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Move")
	void MoveToPlayer();
	virtual void MoveToPlayer_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Move")
	void MoveToRandomPoint(FVector destination);
	virtual void MoveToRandomPoint_Implementation(FVector destination);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartHandAttack();
	virtual void StartHandAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartStompAttack();
	virtual void StartStompAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartJumpAttack();
	virtual void StartJumpAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartSpawnAttack();
	virtual void StartSpawnAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartFireSlamAttack();
	virtual void StartFireSlamAttack_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void SpawnEnemy(FVector destination);
	virtual void SpawnEnemy_Implementation(FVector destination);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckForHit")
	void CheckForHit();
	virtual void CheckForHit_Implementation();

	UFUNCTION(BlueprintCallable, Category = "SwitchState")
	void SwitchState(FString StateKey);

	UPROPERTY()
	float RotationSpeed = 1.5f;
	float MovementSpeed = 10.f;

	UFUNCTION()
	void RotateToPlayer(float DeltaTime);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource) override;

};
