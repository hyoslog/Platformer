// Copyright Kang Hyo Jin. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class PlatformerEditorTarget : TargetRules
{
	public PlatformerEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
		ExtraModuleNames.Add("Platformer");
	}
}
