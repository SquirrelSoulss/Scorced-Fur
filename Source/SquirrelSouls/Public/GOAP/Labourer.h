// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IGOAP.h"
#include "Planner/GOAPGoal.h"
#include "Actions/GOAPAction.h"
#include "Labourer.generated.h"

UCLASS()
class SQUIRRELSOULS_API ALabourer : public ACharacter, public IIGOAP
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	
	ALabourer();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category ="GOAP");
	class UGOAPPlanner* plannerComponent;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GOAP")
	TMap<FString,TSubclassOf<UGOAPGoal>> availableGoals;
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "GOAP")
	TMap<FString,TSubclassOf<UGOAPAction>> availableActions;
	UPROPERTY()
	TArray<UGOAPAction*>myAvailableActions;
	UPROPERTY()
	TArray<UGOAPGoal*> myGoals;
	UPROPERTY()
	TArray<UGOAPAction*> currentPlan;
	bool actionPerformed = false;
	UPROPERTY()
	UGOAPGoal* bestGoal;
	UPROPERTY()
	UGOAPGoal* currentGoal;
	UPROPERTY()
	int32 currentStep = 0;
	UPROPERTY(BlueprintReadOnly)
	bool isIdlyWaiting = false;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual TMap<FString, bool> GetWorldState_Implementation() override;
	virtual TMap<FString, bool> CreateGoalState_Implementation() override;
	virtual void PlanFailed(TMap<FString, bool> failedGoal) override;
	virtual void PlanFound(TMap<FString, bool> goal, TArray<UGOAPAction*> actions) override;
	virtual void ActionsFinished_Implementation() override;
	virtual void PlanAborted_Implementation(UGOAPAction* aborter) override;
	virtual bool MoveAgent_Implementation(UGOAPAction* nextAction) override;

	UGOAPGoal* GetBestGoal();
	void InitialzeActions();
	void InitializeGoals();
	void FollowPlan(float DeltaTime);
};
