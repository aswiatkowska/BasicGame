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

	for (int i = 0; i < GameMode->NumberOfBadPickups; i++)
	{
		SpawnItem(MyBadPickup);
	}
}

void ASpawnZone::SpawnItem(UClass* ItemToSpawn)
{
	XCoordinate1 = FMath::FRandRange(min1, max1);
	XCoordinate2 = FMath::FRandRange(min2, max2);
	YCoordinate1 = FMath::FRandRange(min1, max1);
	YCoordinate2 = FMath::FRandRange(min2, max2);

	FVector Location1(XCoordinate1, YCoordinate1, 40.f);
	FVector Location2(XCoordinate2, YCoordinate2, 40.f);
	FVector Location3(XCoordinate1, YCoordinate2, 40.f);
	FVector Location4(XCoordinate2, YCoordinate1, 40.f);

	randomLoc = FMath::RandRange(1, 4);
	
	if (randomLoc == 1)
	{
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location1, FRotator::ZeroRotator);
	}
	else if (randomLoc == 2)
	{
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location2, FRotator::ZeroRotator);
	}
	else if (randomLoc == 3)
	{
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location3, FRotator::ZeroRotator);
	}
	else
	{
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location4, FRotator::ZeroRotator);
	}
}

