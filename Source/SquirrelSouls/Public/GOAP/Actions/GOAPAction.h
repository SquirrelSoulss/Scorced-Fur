// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GOAPAction.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API UGOAPAction : public UObject
{
	GENERATED_BODY()
private:
	TMap<FString, bool> preconditions;
	TMap<FString, bool> effects;

	bool inRange = false;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	AActor* target;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GOAP")
	float cost = 1;

	void DoReset();
	virtual void Reset();
	virtual bool IsDone();
	virtual bool CheckProceduralPreconditions(AActor* agent);
	virtual bool Perform();
	virtual bool RequiresInRange();

	bool IsInRange();
	void AddPrecondition(FString key, bool value);
	void RemovePrecondition(FString key);
	void AddEffect(FString key, bool value);
	void RemoveEffect(FString key);

	TMap<FString, bool> GetPreconditions();
	TMap<FString, bool> GetEffects();
	UGOAPAction();
};
