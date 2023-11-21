// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GOAPAction.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class SQUIRRELSOULS_API UGOAPAction : public UObject
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GOAP")
	TMap<FString, bool> preconditions ;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GOAP")
	TMap<FString, bool> effects;

	bool inRange = false;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "GOAP")
	AActor* target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float cost = 1;
	ACharacter* myAgent = nullptr;
	bool usesDeltaTime = false;
	FTimerHandle timerHandle;
	void SetAgent(ACharacter* usedAgent);
	void DoReset();
	virtual void Reset();
	virtual bool IsDone();
	virtual bool CheckProceduralPreconditions(AActor* agent);
	virtual bool Perform(float DeltaTime);
	virtual bool RequiresInRange();
	virtual float GetCost();
	virtual void AbortAction();

	bool IsInRange();
	void AddPrecondition(FString key, bool value);
	void RemovePrecondition(FString key);
	void AddEffect(FString key, bool value);
	void RemoveEffect(FString key);

	TMap<FString, bool> GetPreconditions();
	TMap<FString, bool> GetEffects();
	UGOAPAction();
};
