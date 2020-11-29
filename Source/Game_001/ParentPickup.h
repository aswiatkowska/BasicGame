// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentPickup.generated.h"

UCLASS()
class GAME_001_API AParentPickup : public AActor
{
	GENERATED_BODY()
	
public:
	AParentPickup();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

};
