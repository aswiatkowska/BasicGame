
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "CC_GameMode.h"
#include "ParentPickup.generated.h"

UCLASS()
class GAME_001_API AParentPickup : public AActor
{
	GENERATED_BODY()
	
public:
	AParentPickup();

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* CubeMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	float RotationRate = 100;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	virtual void OnOverlap(AActor* OverlappedActor, AActor* OtherActor);

	virtual void DoOverlapActions();

	ACC_GameMode * GameMode;
};
