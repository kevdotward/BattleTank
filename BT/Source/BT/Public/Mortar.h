// Copyright Kev Ward, London, UK.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Mortar.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMortarDelegate);


UCLASS()
class BT_API AMortar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMortar();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const & DamageEvent, class AController * EventInstigator, AActor * DamageCauser) override;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealthPercent() const;

	FMortarDelegate MortarDeath;

private:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	int32 StartingHealth = 100;

	UPROPERTY(VisibleAnywhere, Category = "Health")
	int32 CurrentHealth = StartingHealth;
};
