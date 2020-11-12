// Fill out your copyright notice in the Description page of Project Settings.

#include "CC_Pickup.h"
#include "CC_Pawn.h"

// Sets default values
ACC_Pickup::ACC_Pickup()
{
	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CubeMesh->SetupAttachment(Root);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	PrimaryActorTick.bCanEverTick = true;

	OnActorBeginOverlap.AddDynamic(this, &ACC_Pickup::OnOverlap);

}

// Called when the game starts or when spawned
void ACC_Pickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Pickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));

}

void ACC_Pickup::DeathTimerComplete()
{
	Destroy();
}

void ACC_Pickup::PlayCustomDeath()
{
	GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &ACC_Pickup::DeathTimerComplete, 0.5f, false);
}

void ACC_Pickup::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		Destroy();
	}

}
