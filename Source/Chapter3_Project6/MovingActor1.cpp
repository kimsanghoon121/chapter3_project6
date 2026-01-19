#include "MovingActor1.h"

AMovingActor1::AMovingActor1()
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

	MoveSpeed = 100.0f;
	MaxRange = 1000.0f;
	bMoveForward = true;
}

void AMovingActor1::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();

	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, this, &AMovingActor1::HideActor, 10.0f, false);

	GetWorld()->GetTimerManager().SetTimer(MoveTimerHandle, this, &AMovingActor1::MoveActor, 5.0f, false);

}

void AMovingActor1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	float Distance = FVector::Dist(StartLocation, GetActorLocation());


	if (FMath::IsNearlyZero(MoveSpeed))
	{
		return;
	}
	if (bMoveForward)
	{
		if (Distance < MaxRange)
		{
			AddActorLocalOffset(FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f));
		}
		else if (Distance >= MaxRange)
		{
			bMoveForward = false;
		}
	}
	else
	{
		if (Distance > 1.0f)
		{
			AddActorLocalOffset(FVector(-(MoveSpeed * DeltaTime), 0.0f, 0.0f));
		}
		else if (Distance <= 1.0f)
		{
			bMoveForward = true;
		}
	}
}

void AMovingActor1::HideActor()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, this, &AMovingActor1::ShowActor, 5.0f, false);
}
void AMovingActor1::ShowActor()
{
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	GetWorld()->GetTimerManager().SetTimer(HideTimerHandle, this, &AMovingActor1::HideActor, 10.0f, false);
}

void AMovingActor1::MoveActor()
{
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + FVector(50.0f, 50.0f, 0.0f);
	SetActorLocation(NewLocation);
}

void AMovingActor1::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GetWorld()->GetTimerManager().ClearTimer(HideTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(MoveTimerHandle);

	Super::EndPlay(EndPlayReason);
}
