// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"
//Forward Decleration
class UTankBarrel;
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

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:	
	// Called every frame
	UTankBarrel*Barrel = nullptr;
	void MoveBarrel(FVector AimDirection);

		
};
