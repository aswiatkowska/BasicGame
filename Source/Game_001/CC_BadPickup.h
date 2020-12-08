
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ParentPickup.h"
#include "CC_BadPickup.generated.h"

UCLASS()
class GAME_001_API ACC_BadPickup : public AParentPickup
{
	GENERATED_BODY()	

private:
	virtual void BeginPlay() override;

	virtual void DoOverlapActions() override;

	UFUNCTION()
	void DisableCollision();
};
