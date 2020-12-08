
#include "CC_BadPickup.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ACC_BadPickup::BeginPlay()
{
	Super::BeginPlay();

	GameMode->OnWinDelegate.AddDynamic(this, &ACC_BadPickup::DisableCollision);
}

void ACC_BadPickup::DoOverlapActions()
{
	GameMode->SubtractLifes();

	Destroy();
}

void ACC_BadPickup::DisableCollision()
{
	SetActorEnableCollision(false);
}
