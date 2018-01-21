// Copyright Kev Ward, London, UK.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"


/**
 * 
 */
UCLASS()
class BT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

private:
	virtual void BeginPlay() override;

	//How close can the tank get to the Player Tank?
	float AcceptanceRadius = 3000;
};
