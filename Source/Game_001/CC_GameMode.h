
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

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AddPoint();

	int GetPoints();

	bool CheckWinConditions();

	void SubtractLifes();

	UFUNCTION()
	void RestartGame();

	UPROPERTY(EditAnywhere)
	int NumberOfPickups = FMath::RandRange(4, 8);

	UPROPERTY(EditAnywhere)
	int NumberOfBadPickups = FMath::RandRange(3, 6);

	UPROPERTY(EditAnywhere)
	int NumberOfLifes = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widget")
	TSubclassOf<UUserWidget> WidgetHUD;

private:
	void YouWinMessage();

	void CheckRestartConditions();

	bool IsPawnOffBoard();

	int points = 0;

	UUserWidget* pWidget = nullptr;
};
