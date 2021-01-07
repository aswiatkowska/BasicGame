
#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "Blueprint/UserWidget.h"
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

	pWidget = CreateWidget<UCC_UserWidget>(GetGameInstance(), WidgetHUD);

	pWidget->AddToViewport();

	menuWidget = CreateWidget<UCC_MenuWidget>(GetGameInstance(), WidgetHUD);
}

void ACC_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (IsPawnOffBoard())
	{	
		if (!initialized)
		{
			initialized = true;
			pWidget->DisplayGameOverMessage();
			FTimerHandle handle;
			GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2);
		}
	}
}

void ACC_GameMode::AddPoint()
{
	points++;

	pWidget->UpdatePoints(points);

	YouWin();
}

int ACC_GameMode::GetPoints()
{
	return points;
}

void ACC_GameMode::YouWin()
{
	if (NumberOfPickups == points)
	{
		initialized = true;
		OnWinDelegate.Broadcast();

		pWidget->DisplayYouWinMessage();

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2);
	}
}

void ACC_GameMode::CheckRestartConditions()
{
	if (NumberOfLifes == 0)
	{
		OnGameOverDelegate.Broadcast();

		pWidget->DisplayGameOverMessage();

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2);
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
	pWidget->UpdateLifes(NumberOfLifes);

	CheckRestartConditions();
}

void ACC_GameMode::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "DefaultMap", false);
}

void ACC_GameMode::Pause()
{
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	FInputActionBinding& toggle = InputComponent->BindAction("Pause", IE_Pressed, this, &ACC_GameMode::Pause);
	toggle.bExecuteWhenPaused = true; 
	menuWidget->AddToViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = true;
}

void ACC_GameMode::Unpause()
{
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	menuWidget->RemoveFromViewport();
	GetWorld()->GetFirstPlayerController()->bShowMouseCursor = false;
}