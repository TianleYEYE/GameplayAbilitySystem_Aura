// Tian Le


#include "UI/Widget/AuraUserWidget.h"

void UAuraUserWidget::SetUserWidgetController(UObject* InUserWidgetController)
{
	WidgetController=InUserWidgetController;
	UserWidgetControllerSet();
}
