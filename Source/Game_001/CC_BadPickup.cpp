
#include "CC_BadPickup.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

void ACC_BadPickup::BeginPlay()
{
	Super::BeginPlay();

	Pawn = Cast<ACC_Pawn>(UGameplayStatics::GetActorOfClass(GetWorld(), ACC_Pawn::StaticClass()));

	GameMode->OnWinDelegate.AddDynamic(this, &ACC_BadPickup::DisableCollision);
}

void ACC_BadPickup::DoOverlapActions()
{
	Pawn->ChangeColor();

	GameMode->SubtractLifes();

	Destroy();
}

void ACC_BadPickup::DisableCollision()
{
	SetActorEnableCollision(false);
}
