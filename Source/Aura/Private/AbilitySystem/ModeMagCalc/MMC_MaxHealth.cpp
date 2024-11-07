// Tian Le


#include "AbilitySystem/ModeMagCalc/MMC_MaxHealth.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Intercation/CombatInterface.h"

UMMC_MaxHealth::UMMC_MaxHealth()
{
	VigorDef.AttributeToCapture = UAuraAttributeSet::GetVigorAttribute();//设置需要获取的属性对象
	VigorDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;//设置拾取对象为GE的应用目标
	VigorDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(VigorDef);//添加到捕获属性数值，只有添加到列表，才会去获取属性值
}

float UMMC_MaxHealth::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//  从 source 和 target 获取 Tag
	const FGameplayTagContainer * SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer * TargetTags = Spec.CapturedSourceTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags =SourceTags;
	EvaluateParameters.TargetTags =TargetTags;

	float Vigor = 0.f;
	GetCapturedAttributeMagnitude(VigorDef,Spec,EvaluateParameters,Vigor);
	Vigor = FMath::Max<float>(Vigor,0.f);
	
	ICombatInterface* CombatInterface =Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel =CombatInterface->GetPlayerLevel();

	return 80.f + 2.5f * Vigor + 10.f * PlayerLevel;
}