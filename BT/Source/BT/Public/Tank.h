// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"


//Forward declarations
class UTankBarrel;
class UTankTurret;
class AProjectile;


UCLASS()
class BT_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	UFUNCTION(BlueprintCallable)
	void Fire();

private:
	virtual void BeginPlay() override;

	//TODO To be removed following refactor
	UPROPERTY(EditAnywhere, Category = "Firing")
	float LaunchSpeed = 5000;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 2;

	float LastFireTime = 0;

	UTankBarrel* Barrel = nullptr; //TODO Remove at some point into aiming component.
};
