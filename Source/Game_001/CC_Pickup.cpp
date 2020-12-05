
#include "CC_Pickup.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ACC_Pickup::ACC_Pickup():Super()
{
	PointAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PointAudioComponent"));
	PointAudioComponent->SetupAttachment(RootComponent);
	PointAudioComponent->SetSound(PointSoundCue);
	PointAudioComponent->bAutoActivate = false;
}

void ACC_Pickup::DoOverlapActions()
{
	GameMode->AddPoint();

	SetActorHiddenInGame(true);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	PointAudioComponent->Play(0.f);

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_Pickup::DestroyPickup, 1, true);
}

void ACC_Pickup::DestroyPickup()
{
	Destroy();
}
