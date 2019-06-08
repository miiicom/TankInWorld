// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "TankBarrel.h"
#include "TankProjectile.h"
#include "TankAimingComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect pointers as added at construction?
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));
}

void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
	
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	if (TankAimingComponent) {
		TankAimingComponent->SetBarrelPointer(BarrelToSet);
		Barrel = BarrelToSet;
	}
	else {

	}
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	if (TankAimingComponent) {
		TankAimingComponent->SetTurretPointer(TurretToSet);
	}
	else {

	}
}

void ATank::Fire()
{
	bool isLoaded = (FPlatformTime::Seconds() - LastFireSecond) > ReloadTimeInSeconds;
	if (Barrel &&  isLoaded) {
		
		//spawn projectile
		UE_LOG(LogTemp, Warning, TEXT("Fire triggered"));
		auto projectile = GetWorld()->SpawnActor<ATankProjectile>(ProjectileBP,Barrel->GetSocketLocation(FName("ProjectileStart")), Barrel->GetSocketRotation(FName("ProjectileStart")));
		if (projectile) {
			projectile->LaunchProjectile(this->LaunchSpeed);
		}

		LastFireSecond = FPlatformTime::Seconds();
	}
	else {
		return;
	}
}

