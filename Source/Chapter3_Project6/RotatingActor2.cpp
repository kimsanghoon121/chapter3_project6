#include "RotatingActor2.h"

ARotatingActor2::ARotatingActor2()
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

void ARotatingActor2::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARotatingActor2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	float FractionalRotation = FMath::Sin(RunningTime * RotationSpeed);
	float RotationValue = FractionalRotation * RotationAngle;

	FRotator NewRotation = FRotator(RotationValue, RotationValue, RotationValue);

	SetActorRotation(NewRotation);
}

