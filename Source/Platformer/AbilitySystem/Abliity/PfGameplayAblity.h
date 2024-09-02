// Copyright Kang Hyo Jin. All Rights Reserved.

#pragma once

// Default

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "Abilities/GameplayAbility.h"

// Project-specific

// Local

// Last
#include "PfGameplayAblity.generated.h"

/**
 * Ability 활성화 타이밍
 */
UENUM()
enum class EAbilityActivationTiming : uint8
{
	OnInputTriggered,	// 입력 발생 시 활성화
	WhileInputActive,	// 입력이 활성화된 동안 계속 활성화
	OnStartActive		// 활성화 상태로 시작
};

UCLASS(Abstract)
class PLATFORMER_API UPfGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

public:
	inline EAbilityActivationTiming GetActivationTiming() const { return ActivationTiming; }

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Timing")
	EAbilityActivationTiming ActivationTiming = EAbilityActivationTiming::OnInputTriggered;
};
