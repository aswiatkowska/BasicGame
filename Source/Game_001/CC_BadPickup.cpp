// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_BadPickup.h"

void ACC_BadPickup::DoOverlapActions()
{
	GameMode->SubtractLifes();

	Destroy();
}
