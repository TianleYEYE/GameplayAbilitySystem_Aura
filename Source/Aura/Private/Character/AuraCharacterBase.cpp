// Tian Le


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Weapon =CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}


void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAuraCharacterBase::InitAbilityActorInfo()
{
}

void AAuraCharacterBase::ApplyEffectToTarget(TSubclassOf<UGameplayEffect> GameplayEffectClasss, float Level)
{
	const FGameplayEffectContextHandle ContextHandle =GetAbilitySystemComponent()->MakeEffectContext();
	//创建范围，传入UGameplayEffect，Level，FGameplayEffectContextHandle
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClasss,Level,ContextHandle);
	//将效果应用于持有GetAbilitySystemComponent()的对象，*SpecHandle.Data.Get()对SpecHandle中的数据直接进行引用
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAuraCharacterBase::InilitialzeDefaultAttributes()
{
	ApplyEffectToTarget(DefaultPrimaryAttributes,1.f);
	ApplyEffectToTarget(DefaultSecondaryAttributes,1.f);
}





