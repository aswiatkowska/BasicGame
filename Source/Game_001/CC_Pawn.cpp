// Fill out your copyright notice in the Description page of Project Settings.


#include "CC_Pawn.h"
#include "CC_Pickup.h"
#include "CC_GameMode.h"

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
	MovementForce = 100000;

}

void ACC_Pawn::BeginPlay()
{
	Super::BeginPlay();
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
