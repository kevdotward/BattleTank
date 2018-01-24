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

protected:
	//How close can the tank get to the Player Tank?
	UPROPERTY(EditDefaultsOnly, Category = "Movement")
	float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

};
