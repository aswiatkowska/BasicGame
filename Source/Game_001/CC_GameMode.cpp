// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "CC_Pickup.h"
#include "SpawnZone.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "Blueprint/WidgetTree.h"



ACC_GameMode::ACC_GameMode()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> Blueprint(TEXT("Blueprint'/Game/MyPawn.MyPawn'"));
	if (Blueprint.Object)
	{
		DefaultPawnClass = (UClass*)Blueprint.Object->GeneratedClass;
	}

	WidgetHUD = nullptr;
}

void ACC_GameMode::BeginPlay()
{
	Super::BeginPlay();
	//C:/Users/dell/Desktop/BasicGame/Content/UI.uasset
	FStringClassReference locWidgetClassRef(TEXT("WidgetBlueprint'/Game/UI.UI_C'"));
	if (UClass* locWidgetClass = locWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		pWidget = CreateWidget<UUserWidget>(this->GetGameInstance(), locWidgetClass);
		if (pWidget)
		{
			pWidget->AddToViewport();

			AGameModeBase *locGM = GetWorld()->GetAuthGameMode();
			if (locGM)
			{
				ACC_GameMode *locUIGM = CastChecked<ACC_GameMode>(locGM);
				if (locUIGM)
				{
					locUIGM->WidgetHUD = pWidget;
				}
			}
		}
	}
}

void ACC_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (WidgetHUD)
	{
		const FName locTextControlName = FName(TEXT("ScoreLabel"));
		UTextBlock* locTextControl = (UTextBlock*)(WidgetHUD->WidgetTree->FindWidget(locTextControlName));

		if (locTextControl != nullptr)
		{
			locTextControl->SetText(FText::FromString(FString::FromInt(this->points)));
		}
	}
}

void ACC_GameMode::AddingPoints(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		points++;
	}
}
