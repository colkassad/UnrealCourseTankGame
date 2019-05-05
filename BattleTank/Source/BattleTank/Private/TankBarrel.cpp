// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
    //Move the barrel the right amount this frame
    //given a max elevation speed and the frame time

    //clamp relative speed to between -1 and 1
    auto ClampedRelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

    auto ElevationChange = ClampedRelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
    auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

    auto ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

    SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}
