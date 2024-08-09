// Tian Le


#include "UI/HUD/AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (OverlayWidgetController==nullptr)//当OverlayWidgetController为空时
	{
		//初始化一个OverlayWidgetController
		OverlayWidgetController=NewObject<UOverlayWidgetController>(this,OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(WCParams);
		OverlayWidgetController->BindCallbacksToDependencies();
		//初始化后返回
		return OverlayWidgetController;
	}
	return OverlayWidgetController;
}


void AAuraHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	checkf(OverlayWidgetClass,TEXT("OverLay Widget Class uninitialized,please fill out BP_AuraHUD"))
	checkf(OverlayWidgetControllerClass,TEXT("OverLay Widget Controller Class uninitialized,please fill out BP_AuraHUD"))
	
	UUserWidget *Widget =CreateWidget<UUserWidget>(GetWorld(),OverlayWidgetClass);
	OverlayWidget=Cast<UAuraUserWidget>(Widget);
	
	const FWidgetControllerParams WidgetControllerParams(PC,PS,ASC,AS);
	UOverlayWidgetController *WidgetController=GetOverlayWidgetController(WidgetControllerParams);

	OverlayWidget->SetUserWidgetController(WidgetController);
	OverlayWidgetController->BroadcastInitiaValues();
	
	Widget->AddToViewport();

}
