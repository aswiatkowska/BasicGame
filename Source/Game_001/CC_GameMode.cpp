// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_GameMode.h"
#include "CC_Pawn.h"
#include "CC_Pickup.h"
#include "SpawnZone.h"
#include "Blueprint/UserWidget.h"


ACC_GameMode::ACC_GameMode()
{
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UBlueprint> Blueprint(TEXT("Blueprint'/Game/MyPawn.MyPawn'"));
	if (Blueprint.Object)
	{
		DefaultPawnClass = (UClass*)Blueprint.Object->GeneratedClass;
	}
}

void ACC_GameMode::BeginPlay()
{
	Super::BeginPlay();

	FStringClassReference locWidgetClassRef(TEXT("WidgetBlueprint'/Game/UI.UI_C'"));
	if (UClass* locWidgetClass = locWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		pWidget = CreateWidget<UUserWidget>(this->GetGameInstance(), locWidgetClass);
		if (pWidget)
		{
			pWidget->AddToViewport();

			APawn *locPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
			if (locPawn)
			{
				ACC_Pawn *locUIPawn = CastChecked<ACC_Pawn>(locPawn);
				if (locUIPawn)
				{
					locUIPawn->WidgetHUD = pWidget;
				}
			}
		}
	}
}

void ACC_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
