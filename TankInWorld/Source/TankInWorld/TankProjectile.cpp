// Fill out your copyright notice in the Description page of Project Settings.


#include "TankProjectile.h"
#include "Runtime/Engine/Classes/GameFramework/ProjectileMovementComponent.h"
// Sets default values
ATankProjectile::ATankProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	projectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Move component"));
	projectileMoveComponent->bAutoActivate = false;
}

void ATankProjectile::LaunchProjectile(float speed)
{
	projectileMoveComponent->SetVelocityInLocalSpace(FVector::ForwardVector *  speed); //Forward Vector will be barrel's vector.
	projectileMoveComponent->Activate();
	UE_LOG(LogTemp, Warning, TEXT("Projectile Launched"));
}

// Called when the game starts or when spawned
void ATankProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

