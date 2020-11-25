// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pickup.h"
#include "CC_Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"


ACC_Pickup::ACC_Pickup()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CubeMesh->SetupAttachment(Root);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	static ConstructorHelpers::FObjectFinder<USoundCue> PointSoundCueObject(TEXT("SoundCue'/Game/StarterContent/Audio/PointSoundCue.PointSoundCue'"));
	if (PointSoundCueObject.Succeeded())
	{
		PointSoundCue = PointSoundCueObject.Object;

		PointAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("PointAudioComponent"));
		PointAudioComponent->SetupAttachment(RootComponent);
	}

	OnActorBeginOverlap.AddDynamic(this, &ACC_Pickup::OnOverlap);

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

		if (PointAudioComponent && PointSoundCue)
		{
			PointAudioComponent->Play(0.f);
		}

		Destroy();
	}
}
