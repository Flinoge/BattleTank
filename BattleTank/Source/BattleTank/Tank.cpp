// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    
    TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAxis("Rotate_Turret", this, &ATank::RotateTurret);
    PlayerInputComponent->BindAxis("Elevate_Barral", this, &ATank::ElevateBarral);
    PlayerInputComponent->BindAxis("Rotate_Tank", this, &ATank::RotateTank);
    PlayerInputComponent->BindAxis("Move_Tank", this, &ATank::MoveTank);
}

void ATank::ElevateBarral(float Speed) {
    if (!Barral) { return; }
    float NewSpeed = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
    Barral->AddRelativeRotation(FRotator(NewSpeed, 0, 0));
}

void ATank::RotateTurret(float Speed)
{
    if (!Turret) { return; }
    float NewSpeed = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
    Turret->AddRelativeRotation(FRotator(0, NewSpeed, 0));
}

void ATank::MoveTank(float Speed)
{
    if (!Tank) { return; }
    float NewSpeed = GetWorld()->DeltaTimeSeconds * Speed * MovementSpeed;
//    Tank->AddRelativeRotation(FRotator(0, Speed, 0));
    Tank->AddRelativeLocation(Tank->GetForwardVector() * NewSpeed);
}

void ATank::RotateTank(float Speed)
{
    if (!Tank) { return; }
    float NewSpeed = GetWorld()->DeltaTimeSeconds * Speed * RotationSpeed;
    Tank->AddRelativeRotation(FRotator(0, NewSpeed, 0));
}

void ATank::SetTurretChildActor(UChildActorComponent* TurretFromBP)
{
    if (!TurretFromBP) { return; }
    Turret = TurretFromBP;
    TankAimingComponent->SetTurretReference(TurretFromBP);
}

void ATank::SetBarralChildActor(UChildActorComponent* BarralFromBP)
{
    if (!BarralFromBP) { return; }
    Barral = BarralFromBP;
    TankAimingComponent->SetBarrelReference(BarralFromBP);
}

void ATank::SetTankChildkActor(UStaticMeshComponent* TankFromBP)
{
    if (!TankFromBP) { return; }
    Tank = TankFromBP;
    TankAimingComponent->SetTankReference(TankFromBP);
}

void ATank::AimAt(FVector HitLocation) {
    TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}







