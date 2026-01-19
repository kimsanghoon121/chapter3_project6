#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor3.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API AMovingActor3 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor3();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor3|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor3|Components")
	UStaticMeshComponent* StaticMeshComp;

public:	
	FVector StartLocation;
	float RunningTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	FVector TargetLocation;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MoveSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|RandomSettings")
	float MinSpeed = 0.3f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|RandomSettings")
	float MaxSpeed = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|RandomSettings")
	float MinRange = -600.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement|RandomSettings")
	float MaxRange = 600.0f;

	virtual void Tick(float DeltaTime) override;

};
