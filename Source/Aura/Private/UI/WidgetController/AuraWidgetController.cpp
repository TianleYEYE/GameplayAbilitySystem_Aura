// Tian Le


#include "UI/WidgetController/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WCParams)
{
	PlayerController=WCParams.PlayerController;
	PlayerState=WCParams.PlayerState;
	AbilitySystemComponent=WCParams.AbilitySystemComponent;
	AttributeSet=WCParams.AttributeSet;
	
}

void UAuraWidgetController::BroadcastInitiaValues()
{
}

void UAuraWidgetController::BindCallbacksToDependencies()
{
}
