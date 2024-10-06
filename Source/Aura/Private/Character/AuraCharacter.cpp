// Tian Le


#include "Character/AuraCharacter.h"

#include "Game/AuraPlayerState.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "Player/AuraPlayerController.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement =true ;//键盘朝向作为正确位置
	GetCharacterMovement()->RotationRate = FRotator(0.f,400.f,0.f);
	GetCharacterMovement()->bConstrainToPlane = true;//用于将角色或对象的运动限制在特定平面，有效地使3D世界中的2D运动成为可能。
	GetCharacterMovement()->bSnapToPlaneAtStart = true;//启用平面捕捉

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);
	//初始化能力能力信息到服务器
	InitAbilityActorInfo();
	
	SetOwner(NewController);
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
	//初始化能力信息到客户端
	InitAbilityActorInfo();
	
}

void AAuraCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState *AuraPlayerState=GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AbilitySystemComponent =AuraPlayerState->GetAbilitySystemComponent();
	AbilitySystemComponent->InitAbilityActorInfo(AuraPlayerState,this);
	Cast<UAuraAbilitySystemComponent>(AbilitySystemComponent)->AbilityActorInfoSet();
	
	AttributesSet =AuraPlayerState->GetAttributeSet();

	if (AAuraPlayerController *AuraPlayerController=Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD *AuraHUD =Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController,AuraPlayerState,AbilitySystemComponent,AttributesSet);
		}
	}

	InilitialzeDefaultAttributes();
}