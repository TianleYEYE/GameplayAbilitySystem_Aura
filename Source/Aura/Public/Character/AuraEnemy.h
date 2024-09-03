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
	
	void HighLightAction() override;
	void UnHighLightAction() override;
protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo()override;
	
};
