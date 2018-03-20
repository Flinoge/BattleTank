// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TankAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
    void AimAt(FVector HitLocation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
    
    UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    
    UFUNCTION(BlueprintCallable, Category=Tank)
    void SetTurretChildActor(UChildActorComponent* TurretFromBP);
    
    UFUNCTION(BlueprintCallable, Category=Tank)
    void SetBarralChildActor(UChildActorComponent* BarralFromBP);
    
    UFUNCTION(BlueprintCallable, Category=Tank)
    void SetTankChildkActor(UStaticMeshComponent* TankFromBP);
    
private:
    void MoveTank(float Speed);
    void RotateTank(float Speed);
    void RotateTurret(float Speed);
    void ElevateBarral(float Speed);
    UStaticMeshComponent* Tank = nullptr;
    UChildActorComponent* Turret = nullptr;
    UChildActorComponent* Barral = nullptr;
    
    UPROPERTY(EditAnywhere)
    float MovementSpeed = 1000;
    
    UPROPERTY(EditAnywhere)
    float RotationSpeed = 120;
    
    UPROPERTY(EditAnywhere, Category=Firing)
    float LaunchSpeed = 100000;
	
};
