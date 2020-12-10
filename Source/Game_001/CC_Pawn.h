
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Particles/ParticleSystem.h"
#include "CC_GameMode.h"
#include "CC_Pawn.generated.h"

UCLASS()
class GAME_001_API ACC_Pawn : public APawn
{
	GENERATED_BODY()

public:
	ACC_Pawn();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void ChangeColor();

	UFUNCTION()
	void GameOverAnimation();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UMaterialInstanceDynamic * DynamicMatInstance;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLinearColor DefaultColor = FLinearColor(1, 1, 1, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FLinearColor RedColor = FLinearColor(0.6, 0.05, 0.05, 1);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem * GameOverParticleSystem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector ForwardVector = FVector(1, 0, 0);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector RightVector = FVector(0, 1, 0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce = 100000;

private:
	virtual void BeginPlay() override;

	void MoveUp(float Value);

	void MoveRight(float Value);

	void ChangeColorBack();

	ACC_GameMode * GameMode;
};
