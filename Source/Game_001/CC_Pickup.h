// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/AudioComponent.h"
#include "Sound/SoundCue.h"
#include "ParentPickup.h"
#include "CC_Pickup.generated.h"

UCLASS()
class GAME_001_API ACC_Pickup : public AParentPickup
{
	GENERATED_BODY()
	
public:	
	ACC_Pickup();

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UAudioComponent* PointAudioComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
	class USoundCue* PointSoundCue;

private:
	virtual void DoOverlapActions() override;

	UFUNCTION()
	void DestroyPickup();
};
