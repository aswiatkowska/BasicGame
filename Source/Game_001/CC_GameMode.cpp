
#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"


ACC_GameMode::ACC_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ACC_GameMode::BeginPlay()
{
	Super::BeginPlay();

	pWidget = CreateWidget<UUserWidget>(GetGameInstance(), WidgetHUD);
	pWidget->AddToViewport();
}

void ACC_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPawnOffBoard())
	{	
		if (!initialized)
		{
			initialized = true;
			GameOverMessage();
			FTimerHandle handle;
			GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2, true);
		}
	}
}

void ACC_GameMode::AddPoint()
{
	points++;

	UpdatePoints();

	YouWinMessage();
}

void ACC_GameMode::UpdatePoints()
{
	if (pWidget)
	{
		const FName locTextControlName = FName(TEXT("ScoreLabel"));
		UTextBlock* locTextControl = (UTextBlock*)(pWidget->WidgetTree->FindWidget(locTextControlName));

		if (locTextControl != nullptr)
		{
			locTextControl->SetText(FText::FromString(FString::FromInt(this->points)));
		}
	}
}

int ACC_GameMode::GetPoints()
{
	return points;
}

void ACC_GameMode::YouWinMessage()
{
	if (NumberOfPickups == points)
	{
		initialized = true;
		OnWinDelegate.Broadcast();

		if (pWidget)
		{
			const FName locTextControlName = FName(TEXT("YouWinLabel"));
			UTextBlock* locTextControl = (UTextBlock*)(pWidget->WidgetTree->FindWidget(locTextControlName));

			if (locTextControl != nullptr)
			{
				locTextControl->SetOpacity(1);
			}
		}

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2, true);
	}
}

void ACC_GameMode::CheckRestartConditions()
{
	if (NumberOfLifes == 0)
	{
		OnGameOverDelegate.Broadcast();

		GameOverMessage();

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2, true);
	}
}

void ACC_GameMode::GameOverMessage()
{
	if (pWidget)
		{
			const FName locTextControlName = FName(TEXT("GameOverLabel"));
			UTextBlock* locTextControl = (UTextBlock*)(pWidget->WidgetTree->FindWidget(locTextControlName));

				if (locTextControl != nullptr)
				{
					locTextControl->SetOpacity(1);
				}
		}
}

bool ACC_GameMode::IsPawnOffBoard()
{
	float Z;
	Z = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z;

	return Z < 0.f;
}

bool ACC_GameMode::IsGamePlaying()
{
	if(NumberOfPickups == points || NumberOfLifes == 0 || IsPawnOffBoard())
	{
		return false;
	}
	else
	{
		return true;
	}
}

void ACC_GameMode::SubtractLifes()
{
	ACC_Pawn * Pawn;
	Pawn = Cast<ACC_Pawn>(UGameplayStatics::GetActorOfClass(GetWorld(), ACC_Pawn::StaticClass()));
	Pawn->ChangeColor();

	NumberOfLifes = NumberOfLifes - 1;
	UpdateLifes();

	CheckRestartConditions();
}

void ACC_GameMode::UpdateLifes()
{
	if (pWidget)
	{
		const FName locTextControlName = FName(TEXT("LifesLabel"));
		UTextBlock* locTextControl = (UTextBlock*)(pWidget->WidgetTree->FindWidget(locTextControlName));

		if (locTextControl != nullptr)
		{
			locTextControl->SetText(FText::FromString(FString::FromInt(this->NumberOfLifes)));
		}
	}
}

void ACC_GameMode::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "DefaultMap", false);
}
