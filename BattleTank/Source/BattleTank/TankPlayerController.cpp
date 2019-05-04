// Fill out your copyright notice in the Description page of Project Settings.
#include "TankPlayerController.h"
#include "Engine/World.h"

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
        UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString())

        //TODO Tell controlled tank to aim at this point

    }
    
    
    
}

//Get world location of linetrace through crosshair, true if it hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
    //Find the crosshair position in pixel coordinates
    int32 ViewportSizeX, ViewportSizeY;
    GetViewportSize(ViewportSizeX, ViewportSizeY);
    auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

    //"De-project" the screen position of the crosshair to a world direction
    FVector LookDirection;
    if (GetLookDirection(ScreenLocation, LookDirection))
    {
        //Line trace along that direction and see what we hit (up to a max range)
        GetLookVectorHitLocation(LookDirection, HitLocation);
    }
    return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
    FVector CameraWorldLocation; //To be discarded
    return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
    FHitResult HitResult;
    auto StartLocation = PlayerCameraManager->GetCameraLocation();
    auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
    if (GetWorld()->LineTraceSingleByChannel(HitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
    {
        HitLocation = HitResult.Location;
        return true;
    }
    HitLocation = FVector(0);
    return false;
}