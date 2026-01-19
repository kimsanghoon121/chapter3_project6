#include "SpawnVolume.h"
#include "Components/BoxComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("SpawningBox"));
	SpawningBox->SetupAttachment(Scene);
}

void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
    for (int i = 0; i < SpawnCount; i++)
    {
        if (SpawnArray.Num() > 0)
        {
            int32 RandomIndex = FMath::RandRange(0, SpawnArray.Num() - 1);
            SpawnActor(SpawnArray[RandomIndex]);
        }
    }
}

FVector ASpawnVolume::GetRandomPointInVolume() const
{
    FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
    FVector BoxOrigin = SpawningBox->GetComponentLocation();

    return BoxOrigin + FVector(
        FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
        FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
        FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z)
    );
}

void ASpawnVolume::SpawnActor(TSubclassOf<AActor> ActorClass)
{
    if (!ActorClass) return;

    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;
    GetWorld()->SpawnActor<AActor>(ActorClass, GetRandomPointInVolume(),FRotator::ZeroRotator, SpawnParams);
}

