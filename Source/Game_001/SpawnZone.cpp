// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnZone.h"

// Sets default values
ASpawnZone::ASpawnZone()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
	

}

// Called when the game starts or when spawned
void ASpawnZone::BeginPlay()
{
	Super::BeginPlay();

	for (int i = 0; i < 4; i++)
	{
		SpawnItem(MyPickup);
	}

}

// Called every frame
void ASpawnZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpawnZone::SpawnItem(UClass* ItemToSpawn)
{
	float XCoordinate = FMath::FRandRange(-450.f, 450.f);
	float YCoordinate = FMath::FRandRange(-450.f, 450.f);

	FVector Location(XCoordinate, YCoordinate, 40.f);
	
	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, FRotator(0.f));
}

