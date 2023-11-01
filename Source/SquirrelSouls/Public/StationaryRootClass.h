// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StationaryRootClass.generated.h"

UCLASS()
class SQUIRRELSOULS_API AStationaryRootClass : public AActor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "StateMachine")
	class UStateManagerComponent* stateManager;

public:	
	// Sets default values for this actor's properties
	AStationaryRootClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void NormalAttack();
	virtual void NormalAttack_Implementation();
};
