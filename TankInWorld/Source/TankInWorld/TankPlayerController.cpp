// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

ATank* ATankPlayerController::GetControlledTan() const {

	return Cast<ATank>(GetPawn());
		
		// we can call get pawn because the ATankPlayerController class is a child of player controller
}
