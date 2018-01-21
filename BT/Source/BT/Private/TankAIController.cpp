// Copyright Kev Ward, London, UK.

#include "TankAIController.h"
#include "TankAimingComponent.h"
// Depends on movement component via pathfinding system


void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!ensure(PlayerTank && ControlledTank)) { return; }
	
	//Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius);  //TODO Check this is in CM?

	FVector PlayerTankLocation = PlayerTank->GetActorLocation();
	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	AimingComponent->AimAt(PlayerTankLocation);
	
	AimingComponent->Fire();
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}
