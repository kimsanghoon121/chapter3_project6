#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class CHAPTER3_PROJECT6_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

    //에디터에서 넣을 액터들 선택.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    TArray<TSubclassOf<AActor>> SpawnArray;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
    int32 SpawnCount = 10;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    USceneComponent* Scene;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawning")
    UBoxComponent* SpawningBox;
    UFUNCTION(BlueprintCallable, Category = "Spawning")
    FVector GetRandomPointInVolume() const;
    UFUNCTION(BlueprintCallable, Category = "Spawning")
    void SpawnActor(TSubclassOf<AActor> ActorClass);

protected:
	virtual void BeginPlay() override;
};
