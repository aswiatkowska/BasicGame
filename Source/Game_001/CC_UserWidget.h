
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "CC_UserWidget.generated.h"


UCLASS()
class GAME_001_API UCC_UserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent, Category = "TextDisplay")
	void DisplayYouWinMessage();
	
	UFUNCTION(BlueprintImplementableEvent, Category = "TextDisplay")
	void DisplayGameOverMessage();

	UFUNCTION(BlueprintImplementableEvent, Category = "TextUpdate")
	void UpdatePoints();

	UFUNCTION(BlueprintImplementableEvent, Category = "TextUpdate")
	void UpdateLifes();	
};
