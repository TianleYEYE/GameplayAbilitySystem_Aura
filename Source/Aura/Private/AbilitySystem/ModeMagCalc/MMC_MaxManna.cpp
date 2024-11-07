// Tian Le


#include "AbilitySystem/ModeMagCalc/MMC_MaxManna.h"

#include "AbilitySystem/AuraAttributeSet.h"
#include "Intercation/CombatInterface.h"

UMMC_MaxManna::UMMC_MaxManna()
{
	IntelligenceDef.AttributeToCapture = UAuraAttributeSet::GetIntelligenceAttribute();//设置需要获取的属性对象
	IntelligenceDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;//设置拾取对象为GE的应用目标
	IntelligenceDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(IntelligenceDef);//添加到捕获属性数值，只有添加到列表，才会去获取属性值
}

float UMMC_MaxManna::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	//  从 source 和 target 获取 Tag
	const FGameplayTagContainer * SourceTags = Spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer * TargetTags = Spec.CapturedSourceTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags =SourceTags;
	EvaluateParameters.TargetTags =TargetTags;

	float Intelligence = 0.f;
	GetCapturedAttributeMagnitude(IntelligenceDef,Spec,EvaluateParameters,Intelligence);
	Intelligence = FMath::Max<float>(Intelligence,0.f);
	
	ICombatInterface* CombatInterface =Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
	const int32 PlayerLevel =CombatInterface->GetPlayerLevel();

	return 50.f + Intelligence * 2.5f + PlayerLevel * 15.f;
}