// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "engine.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxDegreesPerSecond = 10;
	
	UPROPERTY(EditAnywhere, Category = SetUp)
	float MaxElevationDegrees = 30;

	UPROPERTY(EditAnywhere, Category = SetUp)
	float MinElevationDegrees = 0;

};
