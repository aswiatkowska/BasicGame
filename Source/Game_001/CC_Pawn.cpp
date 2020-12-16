
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

	DynamicMatInstance = Mesh->CreateAndSetMaterialInstanceDynamic(0);

	GameMode = Cast<ACC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	GameMode->OnGameOverDelegate.AddDynamic(this, &ACC_Pawn::GameOverAnimation);
}

void ACC_Pawn::GameOverAnimation()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), GameOverParticleSystem, GetActorLocation());
	DynamicMatInstance->SetVectorParameterValue(FName("ColorParam"), RedColor);
	Mesh->SetSimulatePhysics(false);
}

void ACC_Pawn::ChangeColor()
{
	DynamicMatInstance->SetVectorParameterValue(FName("ColorParam"), RedColor);

	if (GameMode->NumberOfLifes > 1)
	{
		FTimerHandle handle;
		GetWorld()->GetTimerManager().SetTimer(handle, this, &ACC_Pawn::ChangeColorBack, 0.5);
	}
}

void ACC_Pawn::ChangeColorBack()
{
	DynamicMatInstance->SetVectorParameterValue(FName("ColorParam"), DefaultColor);
}

void ACC_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveUp", this, &ACC_Pawn::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ACC_Pawn::MoveRight);
}

void ACC_Pawn::MoveUp(float Value)
{
	if (GameMode->IsGamePlaying())
	{
		FVector ForceToAdd = ForwardVector * MovementForce * Value;
		Mesh->AddForce(ForceToAdd);
	}
}

void ACC_Pawn::MoveRight(float Value)
{
	if (GameMode->IsGamePlaying())
	{
		FVector ForceToAdd = RightVector * MovementForce * Value;
		Mesh->AddForce(ForceToAdd);
	}
}
