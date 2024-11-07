// Tian Le


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	/*
	 *主属性
	 */
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get()
	.AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("增加力量")
		);
	
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get()
	.AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("增加法术伤害")
		);
	
	GameplayTags.Attributes_Primary_Resilience = UGameplayTagsManager::Get()
	.AddNativeGameplayTag(
		FName("Attributes.Primary.Resilience"),
		FString("恢复力")
		);
	
	GameplayTags.Attributes_Primary_Vigor = UGameplayTagsManager::Get()
	.AddNativeGameplayTag(
		FName("Attributes.Primary.Vigor"),
		FString("活力")
		);

	
	/*
	 * 次级属性
	 */
	GameplayTags.Attributes_Secondary_Armor =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.Armor"),
			FString("减少受到的伤害"));

	
	GameplayTags.Attributes_Secondary_ArmorPenetration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.ArmorPenetration"),
			FString("增加护甲穿透伤害"));

	
	GameplayTags.Attributes_Secondary_BlockChance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.BlockChance"),
			FString("增加格挡几率"));

	
	GameplayTags.Attributes_Secondary_CriticalHitChance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.CriticalHitChance"),
			FString("增加双倍暴击伤害的几率"));
	
	GameplayTags.Attributes_Secondary_CriticalHitDamage =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.CriticalHitDamage"),
			FString("致命一击后增加格外伤害"));
	
	GameplayTags.Attributes_Secondary_CriticalHitResistance =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.CriticalHitResistance"),
			FString("减少攻击敌人的致命命中几率"));
			
	GameplayTags.Attributes_Secondary_HealthRegeneration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.HealthRegeneration"),
			FString("增加每秒回血量"));
	
	GameplayTags.Attributes_Secondary_ManaRegeneration =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.ManaRegeneration"),
			FString("增加每秒回蓝量"));

	GameplayTags.Attributes_Secondary_MaxHealth =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.MaxHealth"),
			FString("最大生命值"));

	GameplayTags.Attributes_Secondary_MaxMana =
		UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Secondary.MaxMana"),
			FString("最大魔力值"));
}