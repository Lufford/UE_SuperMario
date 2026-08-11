// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerUpActor.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APowerUpActor::APowerUpActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    CollisionSphere = CreateDefaultSubobject<USphereComponent>(
        TEXT("CollisionSphere")
    );

    RootComponent = CollisionSphere;

    CollisionSphere->SetSphereRadius(100.0f);

    CollisionSphere->SetCollisionEnabled(
        ECollisionEnabled::QueryOnly
    );

    CollisionSphere->SetCollisionResponseToAllChannels(
        ECR_Overlap
    );

    SphereMesh = CreateDefaultSubobject<UStaticMeshComponent>(
        TEXT("SphereMesh")
    );

    SphereMesh->SetupAttachment(RootComponent);

    CollisionSphere->OnComponentBeginOverlap.AddDynamic(
        this,
        &APowerUpActor::OnSphereOverlap
    );

}

// Called when the game starts or when spawned
void APowerUpActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerUpActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
	NewLocation.Z += DeltaHeight * 10.0f;       //Scale our height by a factor of 20
	DeltaTime *= Magnitude;
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);

}

void APowerUpActor::OnSphereOverlap(
    UPrimitiveComponent* OverlappedComponent,
    AActor* OtherActor,
    UPrimitiveComponent* OtherComp,
    int32 OtherBodyIndex,
    bool bFromSweep,
    const FHitResult& SweepResult)
{
    if (!OtherActor)
    {
        return;
    }

    if (OtherActor->ActorHasTag("Player"))
    {
        // Player picked up the power-up
	    Destroy();
        UE_LOG(LogTemp, Warning, TEXT("Grabbed."));
    }
}

