#include "MovingActor2.h"

AMovingActor2::AMovingActor2()
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

	MoveSpeed = 1.0f;
}

void AMovingActor2::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	TargetLocation = StartLocation + FVector(400.0f, 400.0f, 400.0f);

	RunningTime = 0;
}

void AMovingActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float FractionalLocation = FMath::Sin(RunningTime * MoveSpeed);

	float Alpha = (FractionalLocation + 1.0f) / 2.0f;
	FVector NewLocation = FMath::Lerp(StartLocation, TargetLocation, Alpha);

	SetActorLocation(NewLocation);
}
