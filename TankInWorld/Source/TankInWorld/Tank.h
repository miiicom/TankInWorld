// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel; //Forward Decleration
class UTankTurret;
class UTankAimingComponent;
class ATankProjectile;
UCLASS()
class TANKINWORLD_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();
	void AimAt(FVector HitLocation);
	UTankAimingComponent* TankAimingComponent = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);
	UFUNCTION(BlueprintCallable, Category = setup)
	void Fire();

private:
	UPROPERTY(EditAnywhere, Category = Firing) float LaunchSpeed = 100000.0;
	UPROPERTY(EditAnywhere, Category = Setup) TSubclassOf<ATankProjectile> ProjectileBP; // Alternative: TSubclassOf<UDamageType> from https://docs.unrealengine.com/en-US/Programming/UnrealArchitecture/TSubclassOf/index.html
	UTankBarrel* Barrel = nullptr;
};
