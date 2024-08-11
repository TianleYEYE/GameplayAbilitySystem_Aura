﻿// Tian Le

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AuraUserWidget.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraUserWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	void SetUserWidgetController(UObject* InUserWidgetController);

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UObject>WidgetController;
	
protected:
	UFUNCTION(BlueprintImplementableEvent)
	void UserWidgetControllerSet();
	
};