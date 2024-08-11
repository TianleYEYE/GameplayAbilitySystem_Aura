// Tian Le

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuraEffectActor();
 

protected:
	
	virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effects")
    TSubclassOf<UGameplayEffect> InstanceGamePlayEffectClass;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Applied Effects")
	TSubclassOf<UGameplayEffect> DurationGamePlayEffectClass;
    
	UFUNCTION(BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor,TSubclassOf<UGameplayEffect>GameplayEffectClass);

};
