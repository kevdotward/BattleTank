// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{

		//Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius);  //TODO Check this is in CM?


		FVector PlayerTankLocation = PlayerTank->GetActorLocation();
		ControlledTank->AimAt(PlayerTankLocation);

		ControlledTank->Fire();
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}
