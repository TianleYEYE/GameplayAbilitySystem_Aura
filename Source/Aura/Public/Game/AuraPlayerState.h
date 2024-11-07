// Tian Le

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "AuraPlayerState.generated.h"


class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API AAuraPlayerState : public APlayerState,public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AAuraPlayerState();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual UAbilitySystemComponent *GetAbilitySystemComponent() const override;
	UAttributeSet *GetAttributeSet() const {return AttributesSet;}

	//这里前面加了FORCEINLINE ，可以提升效率，但是不能够使用循环，有一些限制，这里直接返回等级的值，没问题。
	FORCEINLINE int32 GetPlayerLevel() const {return  Level;}
protected:
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributesSet;

private:

	UPROPERTY(VisibleAnywhere,ReplicatedUsing= OnRep_Level)
	int32 Level = 1;

	UFUNCTION()
	void OnRep_Level(int OldLevel);
};
