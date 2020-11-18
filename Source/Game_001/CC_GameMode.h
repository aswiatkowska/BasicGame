// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CC_GameMode.generated.h"

class UUserWidget;

UCLASS(minimalapi)
class ACC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACC_GameMode();

	class UUserWidget* pWidget;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;
};
