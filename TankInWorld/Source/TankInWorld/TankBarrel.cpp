// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"

void UTankBarrel::Elevate(float RelativeDegree)
{
	auto time = GetWorld()->GetDeltaSeconds();
	//UE_LOG(LogTemp, Warning, TEXT("time is  %f"), time);
	float ElevationChange = FMath::Clamp<float>(RelativeDegree,-1.0f,1.0f) * MaxDegreePersecond * time;
	//float ElevationChange = RelativeDegree * MaxDegreePersecond * time;
	float clampedElevationChange = RelativeRotation.Pitch+ ElevationChange;
	
	this->SetRelativeRotation(FRotator(FMath::Clamp<float>(clampedElevationChange, MinElevationDegree, MaxElevationDegree), 0, 0));
}
