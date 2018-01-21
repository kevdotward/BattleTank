// Copyright Kev Ward, London, UK.

#include "TankTrack.h"


void UTankTrack::SetThrottle(float Throttle)
{
	//TODO Need to clamp between 0 and 1 so player can't move too fast.

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

