// Fill out your copyright notice in the Description page of Project Settings.


#include "Floater.h"
#include "Components/StaticMeshComponent.h"
// Sets default values
AFloater::AFloater()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CustomStaticMesh"));

	InitialLocation = FVector(0.0f);
	PlacedLocation = FVector(0.0f);
	WorldOrigin = FVector(0.0f);

	InitialDirection = FVector(0.0f);

	bInitializeFloaterLocations = false;
	bShouldFloat = false;

	InitialForce = FVector(2000000.0f, 0.f, 0.f);
	InitialTorque = FVector(2000000.0f, 0.f, 0.f);

	RunningTime = 0.f;
	A = 0.0f;
	B = 0.0f;
	C = 0.0f;
	D = 0.0f;
}

// Called when the game starts or when spawned
void AFloater::BeginPlay()
{
	Super::BeginPlay();

	float InitialX = FMath::FRandRange(-500.f,500.f);
	float InitialY = FMath::FRandRange(-500.f,500.f);
	float InitialZ = FMath::FRandRange(0.f,500.f);

	InitialLocation.X = InitialX;
	InitialLocation.Y = InitialY;
	InitialLocation.Z = InitialZ;

	//InitialLocation *= 500.0f;

	PlacedLocation = GetActorLocation();

	if (bInitializeFloaterLocations)
	{
		SetActorLocation(InitialLocation);
	}

	BaseZLocation = PlacedLocation.Z;


	/*
	StaticMesh->AddForce(InitialForce);
	StaticMesh->AddTorque(InitialTorque);*/
}

// Called every frame
void AFloater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bShouldFloat)
	{
		/*FHitResult HitResult;
		AddActorLocalOffset(InitialDirection, true, &HitResult);

		FVector HitLocation = HitResult.Location;*/
		FVector NewLocation = GetActorLocation();

		NewLocation.Z = BaseZLocation + A * FMath::Sin(B * RunningTime - C) + D;

		SetActorLocation(NewLocation);
		RunningTime += DeltaTime;

	}

	
}

