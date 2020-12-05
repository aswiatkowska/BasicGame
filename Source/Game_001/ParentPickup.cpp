
#include "ParentPickup.h"
#include "CC_Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

AParentPickup::AParentPickup()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	RootComponent = Root;
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CubeMesh->SetupAttachment(Root);
	CubeMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	RotationRate = 100;

	OnActorBeginOverlap.AddDynamic(this, &AParentPickup::OnOverlap);
}

void AParentPickup::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void AParentPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0, RotationRate * DeltaTime, 0));
}

void AParentPickup::OnOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<ACC_Pawn>(OtherActor) != nullptr)
	{
		DoOverlapActions();
	}
}

void AParentPickup::DoOverlapActions()
{

}
