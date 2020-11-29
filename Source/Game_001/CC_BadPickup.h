// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "CC_GameMode.h"
#include "CC_BadPickup.generated.h"

UCLASS()
class GAME_001_API ACC_BadPickup : public AActor
{
	GENERATED_BODY()
	
public:	
	ACC_BadPickup();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RotationRate;

	UPROPERTY()
	ACC_GameMode * GameMode;

private:
	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
