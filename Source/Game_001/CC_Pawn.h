// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CC_Pawn.generated.h"

UCLASS()
class GAME_001_API ACC_Pawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACC_Pawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float MovementForce;

	void MoveUp(float Value);
	void MoveRight(float Value);


};
