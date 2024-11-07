// Tian Le

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Intercation\EnemyInterface.h"
#include "AuraEnemy.generated.h"

class IEnemyInterface;


UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/** Enemy Interface */
	virtual void HighLightAction() override;
	virtual void UnHighLightAction() override;

	/** Combat Interface */
	virtual int32 GetPlayerLevel() override;

	
	
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo()override;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category= "Character Class Default")
	int Level = 1;
};
