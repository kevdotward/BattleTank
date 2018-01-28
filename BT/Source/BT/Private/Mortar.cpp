// Copyright Kev Ward, London, UK.

#include "Mortar.h"


// Sets default values
AMortar::AMortar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMortar::BeginPlay()
{
	Super::BeginPlay();
	CurrentHealth = StartingHealth;
}

float AMortar::TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser)
{
	int32 DamagePoints = FPlatformMath::RoundToInt(DamageAmount);
	int32 DamageToApply = FMath::Clamp(DamagePoints, 0, CurrentHealth);

	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
	{
		MortarDeath.Broadcast();
	}
	return DamageAmount;
}

float AMortar::GetHealthPercent() const
{
	return (float)CurrentHealth / (float)StartingHealth;
}
