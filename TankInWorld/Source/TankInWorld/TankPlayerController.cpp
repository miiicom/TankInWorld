// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"
#define OUT

ATank* ATankPlayerController::GetControlledTan() const {

	return Cast<ATank>(GetPawn());
		
		// we can call get pawn because the ATankPlayerController class is a child of player controller
}

void ATankPlayerController::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerControllerBeginPlay"));
	ATank* controlledTank = GetControlledTan();
	if (controlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("Current possessing pawn is %S"),*(controlledTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No possesed tank"));
	}
}

void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//UE_LOG(LogTemp, Warning, TEXT("Event Tick"));
	FVector HitLocation;
	//DeprojectScreenPositionToWorld(float ScreenX, float ScreenY, FVector& WorldLocation, FVector& WorldDirection)
	AimTowardCrosshead();
}

void ATankPlayerController::AimTowardCrosshead()
{
	if (!GetControlledTan()) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		//Do a line trace
		//UE_LOG(LogTemp, Warning, TEXT("The cursor hit location is %s"), *(HitLocation.ToString()));
		GetControlledTan()->AimAt(HitLocation);
		
	}
	else {
		HitLocation = FVector(0.f, 0.f, 0.f);
	}
	UE_LOG(LogTemp, Warning, TEXT("The crosshair world space location is %s"), *(HitLocation.ToString()));
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitPosotion)
{
	int32  OUT ViewportX, ViewportY;
	GetViewportSize(ViewportX, ViewportY);
	FVector2D ScreenLocation = FVector2D(ViewportX * CorsshairXLocation, ViewportY * CorsshairYLocation);

	FVector OUT CameraWorldLocation, CameraWorldDirection;
	if (Super::DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, CameraWorldDirection)) {
		
		if (GetLookVectorHitLocation(CameraWorldDirection, OutHitPosotion)) {
			return true;
		}
	}
	
	return false;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector & LookDirection, FVector & HitLocation)
{
	FHitResult HitResult;
	FVector start = PlayerCameraManager->GetCameraLocation();
	FVector end = start + LineTraceRange * LookDirection;
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		start,
		end,
		ECC_Visibility
	)) {
		HitLocation = HitResult.Location;
		return true;
	}
	else {
		return false;
	}
	//
	return false;
}
