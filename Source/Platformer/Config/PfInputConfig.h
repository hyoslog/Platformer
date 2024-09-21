// Copyright Kang Hyo Jin. All Rights Reserved.

#pragma once

// Default

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

// Project-specific

// Local

// Last
#include "PfInputConfig.generated.h"

USTRUCT()
struct FPfInputActionData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag;
};

UCLASS(Const)
class PLATFORMER_API UPfInputConfig : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<FPfInputActionData> InputActionDatas;
};