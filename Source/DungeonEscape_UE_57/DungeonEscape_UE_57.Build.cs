// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DungeonEscape_UE_57 : ModuleRules
{
	public DungeonEscape_UE_57(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"DungeonEscape_UE_57",
			"DungeonEscape_UE_57/Variant_Horror",
			"DungeonEscape_UE_57/Variant_Horror/UI",
			"DungeonEscape_UE_57/Variant_Shooter",
			"DungeonEscape_UE_57/Variant_Shooter/AI",
			"DungeonEscape_UE_57/Variant_Shooter/UI",
			"DungeonEscape_UE_57/Variant_Shooter/Weapons"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
