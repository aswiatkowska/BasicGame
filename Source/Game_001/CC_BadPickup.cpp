// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_BadPickup.h"
#include "CC_Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ACC_BadPickup::ACC_BadPickup()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CubeMesh->SetupAttachment(Root);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	OnActorBeginOverlap.AddDynamic(this, &ACC_BadPickup::OnOverlap);
}

void ACC_BadPickup::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	
}

void ACC_BadPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void ACC_BadPickup::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		Destroy();

		GameMode->RestartGame();
	}
}
