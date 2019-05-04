// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "TankAimingComponent.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h" //put new includes above this one, this one must be last

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    ATank* Tank;
    UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    // Sets default values for this pawn's properties
    ATank();

    void AimAt(FVector HitLocation) const;

    UFUNCTION(BlueprintCallable, Category = Setup)
    void SetBarrelReference(UStaticMeshComponent* BarrelToSet);
};
