#include "RotatingActor3.h"

ARotatingActor3::ARotatingActor3()
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

void ARotatingActor3::BeginPlay()
{
	Super::BeginPlay();
	
	RotationSpeed = FMath::RandRange(MinSpeed, MaxSpeed);
	RotationAngle = FMath::RandRange(MinAngle, MaxAngle);
}

void ARotatingActor3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	float RotationValue = FMath::Sin(RunningTime * RotationSpeed) * MaxAngle;

	SetActorRotation(FRotator(RotationValue, RotationValue, RotationValue));
}

