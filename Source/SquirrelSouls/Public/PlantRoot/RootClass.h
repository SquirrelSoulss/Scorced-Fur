// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RootAnimInstance.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RootClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API ARootClass : public AActor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "StateMachine")
	class UStateManagerComponent* stateManager;

public:
	// Sets default values for this actor's properties
	ARootClass();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	AActor* PlayerRef = nullptr; // change to player class later

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	URootAnimInstance* AnimRef = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	bool CanHit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackVariables")
	bool CanBeParried = false;

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "CheckHit")
	void CheckIfHit();
	virtual void CheckIfHit_Implementation();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void PlayerInRadius();

	UFUNCTION(BlueprintCallable, Category = "States")
	void SwitchState(FString key);

	UFUNCTION(BlueprintCallable, Category = "DoDamage")
	void DoDamageToPlayer(float Damage);
};
