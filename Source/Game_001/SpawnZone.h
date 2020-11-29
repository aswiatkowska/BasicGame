// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	TSubclassOf<AActor> MyPickup;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	TSubclassOf<AActor> MyBadPickup;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float min1 = -450;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float max1 = -50;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float min2 = 50;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = Range)
	float max2 = 450;

protected:
	virtual void BeginPlay() override;

private:
	void SpawnItem(UClass* ItemToSpawn);

	float XCoordinate1;

	float XCoordinate2;

	float YCoordinate1;

	float YCoordinate2;

	int randomLoc;
};
