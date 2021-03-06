// Copyright Kev Ward, London, UK.

#pragma once

#include "engine.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"


/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10;
	
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 45;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0;
};
