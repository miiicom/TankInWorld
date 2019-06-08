// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlTank = Cast<ATank>(GetPawn());

	if (PlayerTank) {
		ControlTank->AimAt(PlayerTank->GetActorLocation());
		ControlTank->Fire();
	}
	
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	ATank* PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank) {
		//UE_LOG(LogTemp, Warning, TEXT("AI found player tank, it is %s"), *(PlayerTank->GetName()));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI can't find player tank"));
	} 
}
