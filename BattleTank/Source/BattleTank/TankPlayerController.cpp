// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
    Super::BeginPlay();
    //UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"))
    
    ATank* Tank = GetControlledTank();
    if (Tank)
    {
        UE_LOG(LogTemp, Warning, TEXT("You are possessing %s"), *Tank->GetName())
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank!"))
    }
}

void ATankPlayerController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
    if (!GetControlledTank()) { return; }
    
    FVector HitLocation; // Out parameter

    if (GetSightRayHitLocation(HitLocation)) //has side-effect, is going to line trace
    {
        UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *HitLocation.ToString())

        //TODO Tell controlled tank to aim at this point

    }
    
    
    
}

//Get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    HitLocation = FVector(1.0);
    return true;
}