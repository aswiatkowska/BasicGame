// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "CC_Pawn.generated.h"

class UUserWidget;

UCLASS()
class GAME_001_API ACC_Pawn : public APawn
{
	GENERATED_BODY()

public:
	
	ACC_Pawn();

public:	

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

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

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Score")
	class UUserWidget* WidgetHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
	int points = 0;

	UFUNCTION()
	void AddingPoints(AActor* OverlappedActor, AActor* OtherActor);
};
