// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pawn.h"

// Sets default values
ACC_Pawn::ACC_Pawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	Mesh->SetSimulatePhysics(true);
	MovementForce = 100000;

}

// Called when the game starts or when spawned
void ACC_Pawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACC_Pawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACC_Pawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveUp", this, &ACC_Pawn::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ACC_Pawn::MoveRight);

}

void ACC_Pawn::MoveUp(float Value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

void ACC_Pawn::MoveRight(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

