
#include "SpawnZone.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ASpawnZone::ASpawnZone()
{	
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);
}

void ASpawnZone::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	Pawn = Cast<ACC_Pawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	for (int i = 0; i < GameMode->NumberOfPickups; i++)
	{
		SpawnItem(MyPickupClass);
	}

	for (int i = 0; i < GameMode->NumberOfBadPickups; i++)
	{
		SpawnItem(MyBadPickupClass);
	}
}

void ASpawnZone::SpawnItem(UClass* ItemToSpawn)
{
	FVector NewPickupLocation = FVector::ZeroVector;
	int LocSearchFails = 0;

	do
	{
		NewPickupLocation = GetSpawnLocation();
		TArray<AActor*> OverlappedActors;
		if (!UKismetSystemLibrary::SphereOverlapActors(GetWorld(), NewPickupLocation, SphereRadius, {}, TSubclassOf<AParentPickup>(), {this, Pawn}, OverlappedActors))
		{
			break;
		}
		++LocSearchFails;
	}while (LocSearchFails < MAX_LOC_SEARCH_COUNT);

	if (LocSearchFails < MAX_LOC_SEARCH_COUNT)
	{
		GetWorld()->SpawnActor<AActor>(ItemToSpawn, NewPickupLocation, FRotator::ZeroRotator);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("New pickup spawn failed."))
	}
}

FVector ASpawnZone::GetSpawnLocation()
{
	float XCoordinate1 = FMath::FRandRange(min1, max1);
	float XCoordinate2 = FMath::FRandRange(min2, max2);
	float YCoordinate1 = FMath::FRandRange(min1, max1);
	float YCoordinate2 = FMath::FRandRange(min2, max2);

	int randomLoc = FMath::RandRange(1, 4);

	FVector Location;
	
	if (randomLoc == 1)
	{
		Location = FVector(XCoordinate1, YCoordinate1, 40.f);
	}
	else if (randomLoc == 2)
	{
		Location = FVector(XCoordinate2, YCoordinate2, 40.f);
	}
	else if (randomLoc == 3)
	{
		Location = FVector(XCoordinate1, YCoordinate2, 40.f);
	}
	else
	{
		Location = FVector(XCoordinate2, YCoordinate1, 40.f);
	}

	return Location;
}
