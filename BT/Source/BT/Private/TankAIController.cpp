// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAIController.h"


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GetPlayerTank())
	{
		FVector PlayerTankLocation = GetPlayerTank()->GetActorLocation();
		GetControlledTank()->AimAt(PlayerTankLocation);
	}
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto PlayerControlledTank = GetPlayerTank();
	if (!PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController cannot find player controlled tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController found Player Tank: %s"), *(PlayerControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());

}
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}
