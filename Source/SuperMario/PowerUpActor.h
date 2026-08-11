// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PowerUpActor.generated.h"

UCLASS()
class SUPERMARIO_API APowerUpActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerUpActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	float RunningTime;
	UPROPERTY(EditAnywhere)
	float Magnitude;
    UPROPERTY(VisibleAnywhere)
    class USphereComponent* CollisionSphere;

    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* SphereMesh;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FloatHeight = 30.0f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float FloatSpeed = 2.0f;

    UFUNCTION()
    void OnSphereOverlap(
        UPrimitiveComponent* OverlappedComponent,
        AActor* OtherActor,
        UPrimitiveComponent* OtherComp,
        int32 OtherBodyIndex,
        bool bFromSweep,
        const FHitResult& SweepResult
    );
};
