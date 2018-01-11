// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * TankTrack is used to set driving force and apply this force to a tank or other tracked vehicle.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BT_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	//Sets a throttle between 0 and 1
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	//Sets a maximum force per track in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Movement)
	float TrackMaxDrivingForce = 400000;

};
