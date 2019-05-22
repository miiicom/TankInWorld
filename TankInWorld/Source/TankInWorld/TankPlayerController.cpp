// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

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
}

void ATankPlayerController::AimTowardCrosshead()
{
	if (!GetControlledTan) {
		return;
	}
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) {
		//Do a line trace
		UE_LOG(LogTemp, Warning, TEXT("The cursor hit location is %s"), *(HitLocation->ToString()));
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitPosotion)
{
	return false;
}
