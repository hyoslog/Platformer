// Copyright Kang Hyo Jin. All Rights Reserved.

#pragma once

// Default

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "GameplayTagContainer.h"

// Project-specific

// Local

// Last
#include "PfAbilitySet.generated.h"

USTRUCT(BlueprintType)
struct FPfGameplayAbilityData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UPfGameplayAbility> Ability;

	UPROPERTY(EditDefaultsOnly)
	int32 AbilityLevel = 1;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag;
};

USTRUCT(BlueprintType)
struct FPfGameplayEffectData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly)
	float EffectLevel = 1.0f;
};

USTRUCT(BlueprintType)
struct FPfGameplayAttributeSetData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<class UPfAttributeSet> AttributeSet;
};

USTRUCT(BlueprintType)
struct FPfAbilitySet_Handle
{
	GENERATED_BODY()

public:
	void AddAbilitySpecHandle(const struct FGameplayAbilitySpecHandle& InHandle);
	void AddGameplayEffectHandle(const struct FActiveGameplayEffectHandle& InHandle);
	void AddAttributeSet(class UAttributeSet* InSet);

public:
	UPROPERTY()
	TArray<FGameplayAbilitySpecHandle> AbilitySpecHandles;

	UPROPERTY()
	TArray<FActiveGameplayEffectHandle> GameplayEffectHandles;

	UPROPERTY()
	TArray<TObjectPtr<class UAttributeSet>> AttributeSets;
};

UCLASS(BlueprintType, Const)
class PLATFORMER_API UPfAbilitySet : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	void GiveToAbilitySystem(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle, UObject* InSourceObject) const;

private:
	void ApplyGameplayAbilityDatas(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle, UObject* InSourceObject) const;
	void ApplyGameplayEffectDatas(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle) const;
	void ApplyAttributeSetDatas(class UPfAbilitySystemComponent* InPfASC, FPfAbilitySet_Handle* InHandle) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TArray<FPfGameplayAbilityData> GameplayAbilityDatas;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TArray<FPfGameplayEffectData> GameplayEffectDatas;

	UPROPERTY(EditDefaultsOnly, Category = "Gameplay Ability")
	TArray<FPfGameplayAttributeSetData> AttributeSetDatas;
};
