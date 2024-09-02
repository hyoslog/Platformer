// Copyright Kang Hyo Jin. All Rights Reserved.

// Default
#include "PfAbilitySet.h"

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "GameplayEffect.h"

// Project-specific
#include "AbilitySystem/Abliity/PfGameplayAblity.h"
#include "AbilitySystem/Attribute/PfAttributeSet.h"
#include "AbilitySystem/PfAbilitySystemComponent.h"

// Local

void FPfAbilitySet_Handle::AddAbilitySpecHandle(const FGameplayAbilitySpecHandle& InHandle)
{
	if (ensure(InHandle.IsValid()))
	{
		AbilitySpecHandles.Add(InHandle);
	}
}

void FPfAbilitySet_Handle::AddGameplayEffectHandle(const FActiveGameplayEffectHandle& InHandle)
{
	if (ensure(InHandle.IsValid()))
	{
		GameplayEffectHandles.Add(InHandle);
	}
}

void FPfAbilitySet_Handle::AddAttributeSet(UAttributeSet* InSet)
{
	AttributeSets.Add(InSet);
}

void UPfAbilitySet::GiveToAbilitySystem(UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle, UObject* InSourceObject) const
{
	check(InPfASC);

	if (InPfASC->IsOwnerActorAuthoritative() == false)
	{
		return;
	}

	ApplyGameplayAbilityDatas(InPfASC, InHandle, InSourceObject);
	ApplyGameplayEffectDatas(InPfASC, InHandle);
	ApplyAttributeSetDatas(InPfASC, InHandle);
}

void UPfAbilitySet::ApplyGameplayAbilityDatas(UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle, UObject* InSourceObject) const
{
	check(InPfASC);

	for (const FPfGameplayAbilityData& AbilityData : GameplayAbilityDatas)
	{
		if (IsValid(AbilityData.Ability) == false)
		{
			ensure(false);
			continue;
		}

		auto* AbilityCDO = AbilityData.Ability->GetDefaultObject<UPfGameplayAbility>();
		check(AbilityCDO);

		FGameplayAbilitySpec AbillitySpec(AbilityCDO, AbilityData.AbilityLevel);
		AbillitySpec.SourceObject = InSourceObject;
		AbillitySpec.DynamicAbilityTags.AddTag(AbilityData.InputTag);

		const FGameplayAbilitySpecHandle AbilitySpecHandle = InPfASC->GiveAbility(AbillitySpec);

		if (InHandle != nullptr)
		{
			InHandle->AddAbilitySpecHandle(AbilitySpecHandle);
		}
	}
}

void UPfAbilitySet::ApplyGameplayEffectDatas(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle) const
{
	check(InPfASC);

	for (const FPfGameplayEffectData& EffectData : GameplayEffectDatas)
	{
		if (IsValid(EffectData.GameplayEffect) == false)
		{
			ensure(false);
			continue;
		}

		const auto* const GameplayEffectCDO = EffectData.GameplayEffect->GetDefaultObject<UGameplayEffect>();
		check(GameplayEffectCDO);

		const FActiveGameplayEffectHandle GameplayEffectHandle = InPfASC->ApplyGameplayEffectToSelf(GameplayEffectCDO, EffectData.EffectLevel, InPfASC->MakeEffectContext());

		if (InHandle != nullptr)
		{
			InHandle->AddGameplayEffectHandle(GameplayEffectHandle);
		}
	}
}

void UPfAbilitySet::ApplyAttributeSetDatas(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle) const
{
	check(InPfASC);

	for (const FPfGameplayAttributeSetData& SetData : AttributeSetDatas)
	{
		if (IsValid(SetData.AttributeSet) == false)
		{
			ensure(false);
			continue;
		}

		auto* NewSet = NewObject<UAttributeSet>(InPfASC->GetOwner(), SetData.AttributeSet);
		check(NewSet);

		InPfASC->AddAttributeSetSubobject(NewSet);

		if (InHandle != nullptr)
		{
			InHandle->AddAttributeSet(NewSet);
		}
	}
}