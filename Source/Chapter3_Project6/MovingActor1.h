#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor1.generated.h"

UCLASS()
class CHAPTER3_PROJECT6_API AMovingActor1 : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor1();

private:
	FTimerHandle HideTimerHandle;
	FTimerHandle MoveTimerHandle;

	void HideActor();
	void ShowActor();
	void MoveActor();

	FVector StartLocation;
	bool bMoveForward;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor1|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor1|Components")
	UStaticMeshComponent* StaticMeshComp;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Movement")
	float MaxRange;

	virtual void Tick(float DeltaTime) override;
};
