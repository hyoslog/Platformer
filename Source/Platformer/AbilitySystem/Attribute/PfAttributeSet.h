// Copyright Kang Hyo Jin. All Rights Reserved.

#pragma once

// Default

// C++ Standard Library

// Third-party Library

// Unreal Engine
#include "AttributeSet.h"

// Project-specific

// Local

// Last
#include "PfAttributeSet.generated.h"

#define PF_ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class PLATFORMER_API UPfAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
};