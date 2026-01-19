#include "MovingActor3.h"

AMovingActor3::AMovingActor3()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/EOL_Content/Meshes/SM_FloorBase.SM_FloorBase"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/EOL_Content/Meshes/Materials/MI_Metal.MI_Metal"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}

void AMovingActor3::BeginPlay()
{
	Super::BeginPlay();

	MoveSpeed = FMath::RandRange(MinSpeed, MaxSpeed);

	StartLocation = GetActorLocation();
	float RandomX = FMath::RandRange(MinRange, MaxRange);
	float RandomY = FMath::RandRange(MinRange, MaxRange);
	float RandomZ = FMath::RandRange(MinRange, MaxRange);

	TargetLocation = StartLocation + FVector(RandomX, RandomY, RandomZ);

	RunningTime = 0;
}

void AMovingActor3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float FractionalLocation = FMath::Sin(RunningTime * MoveSpeed);

	float Alpha = (FractionalLocation + 1.0f) / 2.0f;
	FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);

	SetActorLocation(NewLocation);
}

