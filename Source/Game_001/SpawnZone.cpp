// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnZone.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ASpawnZone::ASpawnZone()
{	
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

void ASpawnZone::BeginPlay()
{
	Super::BeginPlay();

	ACC_GameMode * GameMode;
	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	for (int i = 0; i < GameMode->NumberOfPickups; i++)
	{
		SpawnItem(MyPickup);
	}
}

void ASpawnZone::SpawnItem(UClass* ItemToSpawn)
{
	float XCoordinate = FMath::FRandRange(-450.f, 450.f);
	float YCoordinate = FMath::FRandRange(-450.f, 450.f);

	FVector Location(XCoordinate, YCoordinate, 40.f);
	
	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, FRotator::ZeroRotator);
}

