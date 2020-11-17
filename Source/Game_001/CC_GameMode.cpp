// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pawn.h"
#include "CC_Pickup.h"
#include "CC_GameMode.h"
#include "Blueprint/UserWidget.h"

int points = 0;

ACC_GameMode::ACC_GameMode()
{
	static ConstructorHelpers::FObjectFinder<UBlueprint> Blueprint(TEXT("Blueprint'/Game/MyPawn.MyPawn'"));
	if (Blueprint.Object)
	{
		DefaultPawnClass = (UClass*)Blueprint.Object->GeneratedClass;
	}

}

void ACC_GameMode::BeginPlay()
{
	Super::BeginPlay();
	//C:/Users/dell/Desktop/BasicGame/Content/UI.uasset
	FStringClassReference locWidgetClassRef(TEXT("/Game/UserInterface.UserInterface_C"));
	if (UClass* locWidgetClass = locWidgetClassRef.TryLoadClass<UUserWidget>())
	{
		pWidget = CreateWidget<UUserWidget>(this->GetGameInstance(), locWidgetClass);
		if (pWidget)
		{
			pWidget->AddToViewport();
		}
	}
}

void ACC_GameMode::AddingPoints(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		points = points + 1;
	}
}
