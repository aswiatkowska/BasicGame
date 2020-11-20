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

	void AddPoint();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	class UUserWidget* WidgetHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int points = 0;
};
