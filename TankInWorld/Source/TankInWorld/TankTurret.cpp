// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTurret.h"

void UTankTurret::Rotate(float RelativeDegree)
{
	//TODO craete actual Rotation logic
	UE_LOG(LogTemp, Warning, TEXT("RelativeDegre is  %f"), RelativeDegree);
	auto time = GetWorld()->GetDeltaSeconds();
	float RotationnChange = FMath::Clamp<float>(RelativeDegree, -1.0f, 1.0f) * MaxDegreePersecond * time;
	//float ElevationChange = RelativeDegree * MaxDegreePersecond * time;
	float clampedElevationChange = RelativeRotation.Yaw + RotationnChange;

	this->SetRelativeRotation(FRotator(0.0f,clampedElevationChange, 0.0f));
}
