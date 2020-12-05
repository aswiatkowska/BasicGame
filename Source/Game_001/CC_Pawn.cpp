
#include "CC_Pawn.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

ACC_Pawn::ACC_Pawn()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	Mesh->SetSimulatePhysics(true);
}

void ACC_Pawn::BeginPlay()
{
	Super::BeginPlay();

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

void ACC_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GameOverAnimation();
}

void ACC_Pawn::GameOverAnimation()
{
	if (GameMode->NumberOfLifes == 0)
	{
		SetActorHiddenInGame(true);
		Mesh->SetSimulatePhysics(false);
	}
}

void ACC_Pawn::ChangeColor()
{
	Mesh->SetMaterial(0, RedMaterial);

	FTimerHandle handle;
	GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_Pawn::ChangeColorBack, 0.5, true);
}

void ACC_Pawn::ChangeColorBack()
{
	Mesh->SetMaterial(0, DefaultMaterial);
}

void ACC_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveUp", this, &ACC_Pawn::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ACC_Pawn::MoveRight);
}

void ACC_Pawn::MoveUp(float Value)
{
	FVector ForceToAdd = FVector::ForwardVector * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

void ACC_Pawn::MoveRight(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}
