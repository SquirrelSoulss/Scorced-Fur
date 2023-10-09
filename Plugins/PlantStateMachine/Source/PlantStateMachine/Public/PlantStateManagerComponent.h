// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlantStateBase.h"
#include "PlantStateManagerComponent.generated.h"



UCLASS()
class PLANTSTATEMACHINE_API APlantStateManagerComponent : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlantStateManagerComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(BluePrintReadOnly, EditDefaultsOnly, Category = "State Machine")
	FString InitialState;
	UPROPERTY(BluePrintReadOnly, EditDefaultsOnly, Category = "State Machine")
	TMap<FString, TSubclassOf<UPlantStateBase>> AvailableStates;
	UPROPERTY(BluePrintReadOnly, EditDefaultsOnly, Category = "State Machine Debug")
	bool bDebug = false;
	
	UPROPERTY(BluePrintReadOnly)
	TArray<UPlantStateBase*> StateHistory;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "State Machine Debug", meta = (ClampMin = "0", ClampMax = "10", UIMin = "0", UIMax = "10"))
	int32 StateHistoryLenght;
	UPROPERTY(BluePrintReadOnly)
	UPlantStateBase* CurrentState;

	UPROPERTY()
	TMap<FString, UPlantStateBase*> StateMap;

	UFUNCTION(BluePrintCallable, Category = "State Machine")
	void SwitchStateByKey(FString StateKey);
	UFUNCTION(BluePrintCallable, Category = "State Machine")
	void SwitchState(UPlantStateBase* NewState);
	UFUNCTION(BluePrintCallable, Category = "State Machine")
	void InitStateManager();

private:

	bool bCanTickState = false;
	void InitializeStates();
};
