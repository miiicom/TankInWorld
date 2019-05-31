// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKINWORLD_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	

public:
	void Elevate(float RelativeDegree);
	UPROPERTY(EditAnywhere,Category = setup)
		float MaxDegreePersecond = 20.0f;
	UPROPERTY(EditAnywhere, Category = setup)
		float MinElevationDegree = -10.0f;
	UPROPERTY(EditAnywhere, Category = setup)
		float MaxElevationDegree = 30.0f;


};
