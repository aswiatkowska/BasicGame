// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_BadPickup.h"

ACC_BadPickup::ACC_BadPickup():Super()
{
	
}

void ACC_BadPickup::BeginPlay()
{
	Super::BeginPlay();

}

void ACC_BadPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACC_BadPickup::DoOverlapActions()
{
	Destroy();

	GameMode->RestartGame();
}
