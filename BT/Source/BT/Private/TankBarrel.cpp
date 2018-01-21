// Copyright Kev Ward, London, UK.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel certain amount per frame given maximum rotation speed and clamped maximum rotation value
		RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, +1.0f);

	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}
