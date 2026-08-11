// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileBall.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectileBall::AProjectileBall()
{
    PrimaryActorTick.bCanEverTick = false;

    CollisionSphere = CreateDefaultSubobject<USphereComponent>(
        TEXT("CollisionSphere")
    );

    RootComponent = CollisionSphere;

    CollisionSphere->SetSphereRadius(20.0f);

    BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("BallMesh")
    );

    BallMesh->SetupAttachment(RootComponent);

    ProjectileMovement =
        CreateDefaultSubobject<UProjectileMovementComponent>(
            TEXT("ProjectileMovement")
        );

    ProjectileMovement->InitialSpeed = 1500.0f;
    ProjectileMovement->MaxSpeed = 1500.0f;
    ProjectileMovement->bRotationFollowsVelocity = true;
    ProjectileMovement->bShouldBounce = true;
    ProjectileMovement->Bounciness = 0.5f;
}

// Called when the game starts or when spawned
void AProjectileBall::BeginPlay()
{
    Super::BeginPlay();
}

// Called every frame
void AProjectileBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

