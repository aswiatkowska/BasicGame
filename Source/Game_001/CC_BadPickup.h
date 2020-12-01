// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentPickup.h"
#include "CC_BadPickup.generated.h"

UCLASS()
class GAME_001_API ACC_BadPickup : public AParentPickup
{
	GENERATED_BODY()
	
public:	
	ACC_BadPickup();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

private:
	virtual void DoOverlapActions() override;

};
