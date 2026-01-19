#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor3.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API ARotatingActor3 : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor3();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor3|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor3|Components")
	UStaticMeshComponent* StaticMeshComp;

public:	
	virtual void Tick(float DeltaTime) override;

	float RunningTime;
	float RotationSpeed;
	float RotationAngle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	float MinSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	float MaxSpeed = 5.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	float MinAngle = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Random")
	float MaxAngle = 90.0f;
};
