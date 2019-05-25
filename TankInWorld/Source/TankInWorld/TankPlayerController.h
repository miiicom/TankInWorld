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
class TANKINWORLD_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATank* GetControlledTan() const;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
private:
	void AimTowardCrosshead();
	bool GetSightRayHitLocation(FVector& OutHitPosotion);
	bool GetLookVectorHitLocation(FVector& LookDirection, FVector & HitLocation);
	UPROPERTY(EditAnyWhere)float CorsshairXLocation = 0.5;
	UPROPERTY(EditAnyWhere)float CorsshairYLocation = 0.33;
	float LineTraceRange = 100000;
	
};
