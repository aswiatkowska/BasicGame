
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentPickup.h"
#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "SpawnZone.generated.h"

UCLASS()
class GAME_001_API ASpawnZone : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnZone();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	TSubclassOf<AParentPickup> MyPickupClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	TSubclassOf<AParentPickup> MyBadPickupClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float SphereRadius = 20.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float min1 = -450;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float max1 = -50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float min2 = 50;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Range)
	float max2 = 450;

private:
	virtual void BeginPlay() override;

	void SpawnItem(UClass* ItemToSpawn);

	FVector GetSpawnLocation();

	int MAX_LOC_SEARCH_COUNT = 2;

	ACC_Pawn * Pawn;

	ACC_GameMode * GameMode;
};
