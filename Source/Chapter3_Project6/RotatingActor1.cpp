#include "RotatingActor1.h"

ARotatingActor1::ARotatingActor1()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	StaticMeshComp->SetRelativeLocation(FVector(OrbitRadius, 0.0f, 0.0f));

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

void ARotatingActor1::BeginPlay()
{
	Super::BeginPlay();
}

void ARotatingActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}
/*
	만약 위의 Constructor에서
	StaticMeshComp->SetRelativeLocation(FVector(OrbitRadius, 0.0f, 0.0f));을 안쓰고 구현해본다면,
	Move하는방식으로.
	ex)
	//BeginPlay()에서
	StartLocation = GetActorLocation();

	//Tick()에서
	RunningTime += DeltaTime;
	FVector NewLocation = StartLocation;

	//MoveSpeed를 1.0f로 초기화하고, Amplitude = 1000.0f초기화 한다면이라는 가정하에
	NewLocation.Z += FMath::Sin(RunningTime * MoveSpeed) * Amplitude;
	NewLocation.Y += FMath::Cos(RunningTime * MoveSpeed) * Amplitude;

	SetActorLocation(NewLocation);
	*/
