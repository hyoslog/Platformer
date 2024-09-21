// Copyright Kang Hyo Jin. All Rights Reserved.

#pragma once

// Default

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "Engine/DataAsset.h"

// Project-specific

// Local

// Last
#include "PfPawnData.generated.h"

UCLASS(Const)
class PLATFORMER_API UPfPawnData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly)
	TArray<class UPfAbilitySet*> AbilitySets;

	UPROPERTY(EditDefaultsOnly)
	class UPfInputConfig* InputConfig;
};