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

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    auto PlayerTank = GetPlayerTank();
    if (PlayerTank)
    {
        //TODO Move towards the player

        //Aim towards the player
        GetControlledTank()->AimAt(PlayerTank->GetActorLocation());

        //Fire if ready
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
