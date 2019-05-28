// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::AimAt(FVector & AimLocation, float LaunchSpeed)
{
	auto Tankname = GetOwner()->GetName();
	if (!Barrel) {
		return;
	}
	FVector LaunchVelocity = FVector(0);
	FVector BarrelLocation = Barrel->GetSocketLocation(FName("ProjectileStart"));
	if(UGameplayStatics::SuggestProjectileVelocity
		(
			this,
			LaunchVelocity,
			BarrelLocation,
			AimLocation,
			LaunchSpeed,
			false,
			0.0f,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace
		))
	{
		FVector NormalizedLaunchVelocity = LaunchVelocity.GetSafeNormal();
		UE_LOG(LogTemp, Warning, TEXT("%s is aiming at %s, its barrel location is %s, it is shooting at direction %s"), *Tankname, *(AimLocation.ToString()), *(BarrelLocation.ToString()), *NormalizedLaunchVelocity.ToString());
	}

	
}

// Called when the game starts
void UTankAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimingComponent::SetBarrelPointer(UStaticMeshComponent * BarrelToSet)
{
	Barrel = BarrelToSet;
	UE_LOG(LogTemp, Warning, TEXT("Tank aiming component holds barrel,its name is  %s"), *(Barrel->GetName()));

}

