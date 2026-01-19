#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor2.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API AMovingActor2 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor2();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor2|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor2|Components")
	UStaticMeshComponent* StaticMeshComp;

public:	

	FVector StartLocation;
	float RunningTime;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FVector TargetLocation;
	UPROPERTY(EditAnywhere, Category = "Movement")
	float MoveSpeed;

	virtual void Tick(float DeltaTime) override;

};
