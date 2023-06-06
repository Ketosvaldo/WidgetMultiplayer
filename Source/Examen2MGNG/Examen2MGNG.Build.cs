// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Examen2MGNG : ModuleRules
{
	public Examen2MGNG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
