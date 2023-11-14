// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyBaseClass.h"
#include "IDamageRecievers.h"
#include "PlantProjectile.h"
#include "StationaryPlantClass.generated.h"

/**
 * 
 */
UCLASS()
class SQUIRRELSOULS_API AStationaryPlantClass : public AEnemyBaseClass, public IIDamageRecievers
{
	GENERATED_BODY()

public:
	AStationaryPlantClass();
	virtual void PlayerSpotted_Implementation();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges") //move to StationaryPlantplantClass
		FRotator targetBoneRotation;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = Projectile)
	TSubclassOf<class APlantProjectile> ProjectileClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	class UArrowComponent* ShootRef;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool rangedAttackCall = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool changeState = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool meleeAttackTrigger = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoolChanges")
	bool damaged = false;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
	virtual void OnSePawn(APawn* player) ;
	virtual void TakeDamage_Implementation(float Damage, float Poise, bool FireDamage, float KnockbackValue, FVector KnockbackSource) override;
	void ShootProjectile();
};
