// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetControlledTank()) {
		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
	
}

ATank* ATankAIController::GetControlledTank() const{
	return Cast<ATank>(GetPawn());

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	//UE_LOG(LogTemp, Warning, TEXT("%s location is  %s"), *(PlayerTank->GetName()),*(PlayerTank->GetActorLocation().ToString()));
	if (!PlayerTank) { 
		return nullptr; 
	}
	return Cast<ATank>(PlayerTank);
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = GetPlayerTank();
	if (PlayerTank) {
		//UE_LOG(LogTemp, Warning, TEXT("AI found player tank, it is %s"), *(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI can't find player tank"));
	} 
}
