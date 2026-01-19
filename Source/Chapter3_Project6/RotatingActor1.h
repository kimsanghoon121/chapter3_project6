#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor1.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API ARotatingActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor1();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor1|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor1|Components")
	UStaticMeshComponent* StaticMeshComp;


public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float OrbitRadius = 1000.0f;
};

/*
FVector StartLocation;
float RunningTime = 0.0f;
float MoveSpeed = 1.0f;
float Amplitude = 1000.0f;
*/