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
 * Ability Ȱ��ȭ Ÿ�̹�
 */
UENUM()
enum class EAbilityActivationTiming : uint8
{
	OnInputTriggered,	// �Է� �߻� �� Ȱ��ȭ
	WhileInputActive,	// �Է��� Ȱ��ȭ�� ���� ��� Ȱ��ȭ
	OnStartActive		// Ȱ��ȭ ���·� ����
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
