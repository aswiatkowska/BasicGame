// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnZone.generated.h"

UCLASS()
class GAME_001_API ASpawnZone : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ASpawnZone();

protected:
	
	virtual void BeginPlay() override;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	UStaticMeshComponent* Floor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Zone)
	TSubclassOf<AActor> MyPickup;

	UPROPERTY(EditAnywhere)
	int NumberOfPickups = FMath::RandRange(4, 8);

	void SpawnItem(UClass* ItemToSpawn);

};
