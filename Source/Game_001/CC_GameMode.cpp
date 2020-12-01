// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "CC_Pickup.h"
#include "SpawnZone.h"
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

	CheckRestartConditions();
}

void ACC_GameMode::AddPoint()
{
	points++;

	YouWinMessage();

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

void ACC_GameMode::YouWinMessage()
{
	if (NumberOfPickups == points)
	{
		if (pWidget)
		{
			const FName locTextControlName = FName(TEXT("YouWinLabel"));
			UTextBlock* locTextControl = (UTextBlock*)(pWidget->WidgetTree->FindWidget(locTextControlName));

			if (locTextControl != nullptr)
			{
				locTextControl->SetOpacity(1);
			}
		}
	}
}

void ACC_GameMode::CheckRestartConditions()
{
	if ((NumberOfPickups == points) || IsPawnOffBoard())
	{	
		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_GameMode::RestartGame, 2, true);
	}
}

void ACC_GameMode::RestartGame()
{
	UGameplayStatics::OpenLevel(this, "DefaultMap", false);
}

bool ACC_GameMode::IsPawnOffBoard()
{
	float Z;
	Z = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation().Z;

	return Z < 10.f;
	
}

int ACC_GameMode::getPoints()
{
	return points;
}