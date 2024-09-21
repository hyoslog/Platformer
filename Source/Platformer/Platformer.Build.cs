// Copyright Kang Hyo Jin. All Rights Reserved.

using UnrealBuildTool;

public class Platformer : ModuleRules
{
	public Platformer(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(
            new string[] {
                "Platformer"
            }
        );

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "GameplayAbilities", "GameplayTags", "GameplayTasks", "ModularGameplay" });
    }
}
