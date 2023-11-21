// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IDamageRecievers.h"
#include "IEntObserver.h"
#include "EntClass.generated.h"

USTRUCT(BlueprintType)
struct FEntAttackTypeData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString StateName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackRange;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float Weight;
};

USTRUCT(BlueprintType)
struct FAvailableCombos
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TArray<FString> ComboArray;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	bool isFire;
};

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

	UPROPERTY(EditAnywhere, Category = "References")
	UAnimInstance* AnimRef = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckForHit")
	bool IsAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool CanMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool CanSpawn = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	bool IsRotatingInPlace = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Death")
	bool IsDead = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attacks")
	bool IsFireDamage = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CanMove")
	float ChilloutPeriod = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<FEntAttackTypeData> AvailableAttacks;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	bool IsCombo = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	bool IsFireCombo = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TArray<FAvailableCombos> AvailableCombos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combo")
	TArray<FString> ChosenCombo;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "SensedPlayer")
	virtual void StartFight(APawn* player);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Move")
	void MoveToRandomPoint(FVector destination);
	virtual void MoveToRandomPoint_Implementation(FVector destination) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartHandAttack(bool combo = false, bool fire = false);
	virtual void StartHandAttack_Implementation(bool combo = false, bool fire = false) {}

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartStompAttack(bool combo = false);
	virtual void StartStompAttack_Implementation(bool combo = false) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartJumpAttack();
	virtual void StartJumpAttack_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartSpawnAttack();
	virtual void StartSpawnAttack_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void StartFireSlamAttack();
	virtual void StartFireSlamAttack_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "AttackTypes")
	void SpawnEnemy(FVector destination);
	virtual void SpawnEnemy_Implementation(FVector destination) {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Combo")
	void StartCombo();
	virtual void StartCombo_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckForHit")
	void CheckForHit();
	virtual void CheckForHit_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckForHit")
	void CheckFireTransition();
	virtual void CheckFireTransition_Implementation() {};

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Death")
	void Died();
	virtual void Died_Implementation() {};

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

	virtual void TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource)  override {};
};
