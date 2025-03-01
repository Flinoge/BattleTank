// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
    
public:
    ATank* GetControlledTank() const;
	
    virtual void BeginPlay() override;
    
    virtual void Tick(float DeltaTime) override;
    
private:
    void AimTowardsCrosshair();
	
    bool GetSightRayHitLocation(FVector& HitLocation) const;
    
    UPROPERTY(EditAnywhere)
    float CrosshairXLocation = 0.5;
    
    UPROPERTY(EditAnywhere)
    float CrosshairYLocation = 0.333;
    
    UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000.0;
    
    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
    
    bool GetLookVectorHitLocation(FVector LookDirection, FVector &HitLocation) const;
};
