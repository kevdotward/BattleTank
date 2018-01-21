// Copyright Kev Ward, London, UK.

#pragma once

#include "engine.h"
#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"


/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 45;
};
