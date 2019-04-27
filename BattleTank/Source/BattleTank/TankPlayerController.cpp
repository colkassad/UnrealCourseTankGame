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

    //UE_LOG(LogTemp, Warning, TEXT("Aiming towards the crosshair!"))

    //Get world location if linetrace through crosshair
    //If it hits the landscape
        //Tell controlled tank to aim at this point
}