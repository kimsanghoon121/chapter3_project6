#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor2.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API ARotatingActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor2();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor2|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotatingActor2|Components")
	UStaticMeshComponent* StaticMeshComp;

public:	
	virtual void Tick(float DeltaTime) override;

	float RunningTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationAngle = 15.0f;
};
