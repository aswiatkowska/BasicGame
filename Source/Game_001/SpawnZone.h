// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentPickup.h"
#include "CC_GameMode.h"
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

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float min1 = -450;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float max1 = -50;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float min2 = 50;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float max2 = 450;

private:
	virtual void BeginPlay() override;

	void SpawnItem(UClass* ItemToSpawn);

	ACC_GameMode * GameMode;

	float XCoordinate1;

	float XCoordinate2;

	float YCoordinate1;

	float YCoordinate2;

	int randomLoc;
};
