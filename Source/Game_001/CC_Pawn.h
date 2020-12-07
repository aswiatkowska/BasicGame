
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

	void ChangeColor();

	void ChangeColorBack();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void GameOverAnimation();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UMaterial * RedMaterial;

	UPROPERTY(EditAnywhere)
	UMaterial * DefaultMaterial;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UParticleSystemComponent * GameOverParticleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UParticleSystem * GameOverParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementForce = 100000;

private:
	virtual void BeginPlay() override;

	void MoveUp(float Value);

	void MoveRight(float Value);

	ACC_GameMode * GameMode;
};
