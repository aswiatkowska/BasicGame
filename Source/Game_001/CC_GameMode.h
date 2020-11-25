// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CC_GameMode.generated.h"


UCLASS(minimalapi)
class ACC_GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACC_GameMode();

	class UUserWidget* pWidget;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AddPoint();

	void YouWinMessage();

	void CheckRestartConditions();

	bool IsPawnOffBoard();

	int getPoints();

	UFUNCTION()
	void RestartGame();

	UPROPERTY(EditAnywhere)
	int NumberOfPickups = FMath::RandRange(4, 8);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	class UUserWidget* WidgetHUD;

private:
	int points = 0;
};
