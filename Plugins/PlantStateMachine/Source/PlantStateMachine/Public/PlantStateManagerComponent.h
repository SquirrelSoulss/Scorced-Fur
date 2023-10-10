// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlantStateBase.h"
#include "PlantStateManagerComponent.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PLANTSTATEMACHINE_API UPlantStateManagerComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPlantStateManagerComponent();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick ticktype, FActorComponentTickFunction* ThisTickFunction) override;
	
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

	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void SwitchStateByKey(FString StateKey);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void SwitchState(UPlantStateBase* NewState);
	UFUNCTION(BlueprintCallable, Category = "State Machine")
	void InitStateManager();

private:

	bool bCanTickState = false;
	void InitializeStates();
};
