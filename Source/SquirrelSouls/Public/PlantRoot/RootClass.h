// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

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
    UAnimInstance* AnimRef = nullptr;


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
