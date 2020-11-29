// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pickup.h"
#include "CC_Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


ACC_Pickup::ACC_Pickup()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CubeMesh->SetupAttachment(Root);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	OnActorBeginOverlap.AddDynamic(this, &ACC_Pickup::OnOverlap);

	PointAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PointAudioComponent"));
	PointAudioComponent->SetupAttachment(RootComponent);
	PointAudioComponent->SetSound(PointSoundCue);
	PointAudioComponent->bAutoActivate = false;
}

void ACC_Pickup::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ACC_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ACC_Pickup::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		GameMode->AddPoint();

		SetActorHiddenInGame(true);
		CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
		PointAudioComponent->Play(0.f);

		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_Pickup::DestroyPickup, 1, true);
	}
}

void ACC_Pickup::DestroyPickup()
{
	Destroy();
}
