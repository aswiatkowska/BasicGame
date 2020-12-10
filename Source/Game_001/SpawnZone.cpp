
#include "SpawnZone.h"
#include "CC_Pawn.h"
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

	for (int i = 0; i < GameMode->NumberOfPickups; i++)
	{
		if (UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, SphereRadius, {}, TSubclassOf<AParentPickup>(), {}, OverlappedActors))
		{
			SpawnItem(MyPickupClass);
		}
	}

	for (int i = 0; i < GameMode->NumberOfBadPickups; i++)
	{
		if (UKismetSystemLibrary::SphereOverlapActors(GetWorld(), Location, SphereRadius, {}, TSubclassOf<AParentPickup>(), {}, OverlappedActors))
		{
			SpawnItem(MyBadPickupClass);
		}
	}
}

void ASpawnZone::SpawnItem(UClass* ItemToSpawn)
{
	XCoordinate1 = FMath::FRandRange(min1, max1);
	XCoordinate2 = FMath::FRandRange(min2, max2);
	YCoordinate1 = FMath::FRandRange(min1, max1);
	YCoordinate2 = FMath::FRandRange(min2, max2);

	randomLoc = FMath::RandRange(1, 4);
	
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

	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, FRotator::ZeroRotator);
}
