// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
 #include "Kismet/GameplayStatics.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTankAimingComponent::SetBarrelReference(UChildActorComponent* BarrelToSet) {
    if (!BarrelToSet) { return; }
    MyBarrel = BarrelToSet;
}

void UTankAimingComponent::SetTurretReference(UChildActorComponent* TurretToSet) {
    if (!TurretToSet) { return; }
    Turret = TurretToSet;
}

void UTankAimingComponent::SetTankReference(UStaticMeshComponent* TankToSet) {
    if (!TankToSet) { return; }
    Tank = TankToSet;
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed) {
    if (!MyBarrel) { return; }
    if (!Tank) { return; }
    FVector OutLaunchVelocity;
    FVector StartLocation = Tank->GetSocketLocation(FName("Projectile"));
    
    if (UGameplayStatics::SuggestProjectileVelocity(this, OutLaunchVelocity, StartLocation, HitLocation, LaunchSpeed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace)) {
        auto AimDirection = OutLaunchVelocity.GetSafeNormal();
        MoveBarrel(AimDirection);
    
    }
}

void UTankAimingComponent::MoveBarrel(FVector AimDirection) {
    if (!MyBarrel) { return; }
    
    auto BarrelRotation = MyBarrel->GetForwardVector().Rotation();
    auto AimAsRotator = AimDirection.Rotation();
    auto DeltaRotator = AimAsRotator - BarrelRotation;
    
    auto TankName = GetOwner()->GetName();
    UE_LOG(LogTemp, Warning, TEXT("%s aiming at: %s"), *TankName, *AimAsRotator.ToString());
    
    MyBarrel->AddRelativeRotation(FRotator(5, 0, 0));
    
}












