// Copyright Kev Ward, London, UK.

#include "TankAIController.h"
#include "Tank.h"
#include "Mortar.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);
	if (Cast<ATank>(InPawn))
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		PossessedTank->TankDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedPawnDeath);
	}
	else if (Cast<AMortar>(InPawn))
	{
		auto PossessedMortar = Cast<AMortar>(InPawn);
		PossessedMortar->MortarDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedPawnDeath);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }

	//Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);

	FVector PlayerTankLocation = PlayerTank->GetActorLocation();
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTankLocation);

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::OnPossessedPawnDeath()
{
	if (!GetPawn()) { return; }
	GetPawn()->DetachFromControllerPendingDestroy();
}
