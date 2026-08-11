// ProjectileBall.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileBall.generated.h"

UCLASS()
class SUPERMARIO_API AProjectileBall : public AActor
{
    GENERATED_BODY()   

public:
    AProjectileBall();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(VisibleAnywhere)
    class USphereComponent* CollisionSphere;

    UPROPERTY(VisibleAnywhere)
    class UStaticMeshComponent* BallMesh;

    UPROPERTY(VisibleAnywhere)
    class UProjectileMovementComponent* ProjectileMovement;
};