// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "CC_GameMode.h"
#include "CC_Pickup.generated.h"

UCLASS()
class GAME_001_API ACC_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	

	ACC_Pickup();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RotationRate;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* PointAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundCue* PointSoundCue;

	UPROPERTY()
	ACC_GameMode * GameMode;

private:

	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void DestroyPickup();
};
