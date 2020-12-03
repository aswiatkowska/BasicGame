// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_BadPickup.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ACC_BadPickup::BeginPlay()
{
	Super::BeginPlay();

	Pawn = Cast<ACC_Pawn>(UGameplayStatics::GetActorOfClass(GetWorld(), ACC_Pawn::StaticClass()));
}

void ACC_BadPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (GameMode->CheckWinConditions())
	{
		SetActorEnableCollision(false);
	}
}

void ACC_BadPickup::DoOverlapActions()
{
	GameMode->SubtractLifes();

	Pawn->ChangeColor();

	Destroy();
}
