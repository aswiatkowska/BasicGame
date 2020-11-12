// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "CC_Pickup.generated.h"

UCLASS()
class GAME_001_API ACC_Pickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACC_Pickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	FTimerHandle DeathTimerHandle;

	void DeathTimerComplete();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CubeMesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RotationRate;

	void PlayCustomDeath();

	UFUNCTION()
	void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
