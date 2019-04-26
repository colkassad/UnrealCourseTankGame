// Fill out your copyright notice in the Description page of Project Settings.
#include "TankAIController.h"
#include "TankPlayerController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
    Super::BeginPlay();

    ATank* PlayerTank = GetPlayerTank();

    if (PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController has found player tank: %s"), *PlayerTank->GetName())
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("TankAIController has NOT found a player tank!"))
    }
}

ATank* ATankAIController::GetControlledTank() const
{
    return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
    ATankPlayerController* PlayerController = Cast<ATankPlayerController>(GetWorld()->GetFirstPlayerController());
    return Cast<ATank>(PlayerController->GetPawn());
}
