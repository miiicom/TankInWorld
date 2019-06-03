// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * Class for customize turret 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class TANKINWORLD_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
	void Rotate(float RelativeDegree);
	UPROPERTY(EditAnywhere, Category = setup)
		float MaxDegreePersecond = 20.0f;
	UPROPERTY(EditAnywhere, Category = setup)
		float MinRotationDegree = -10.0f;
	UPROPERTY(EditAnywhere, Category = setup)
		float MaxRotationDegree = 30.0f;
	
};
