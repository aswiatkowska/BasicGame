// Fill out your copyright notice in the Description page of Project Settings.

#include "ParentPickup.h"

AParentPickup::AParentPickup()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AParentPickup::BeginPlay()
{
	Super::BeginPlay();
	
}

void AParentPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

