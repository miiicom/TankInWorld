// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//Forward Decleration
class UTankBarrel;
class UTankTurret;
//Hold parameters for barrels and contrl the elevation and rotation
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKINWORLD_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();
	void AimAt(FVector &AimLocation, float LaunchSpeed);
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	void SetBarrelPointer(UTankBarrel* BarrelToSet);
	void SetTurretPointer(UTankTurret* TurretToSet);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	// Called every frame
	UTankBarrel*Barrel = nullptr;
	UTankTurret*Turret = nullptr;
	void MoveBarrel(FVector AimDirection);
	void MoveTurret(FVector AimDirection);

		
};
