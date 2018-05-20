// JackMyth Personal

using UnrealBuildTool;

public class MyMusicGame : ModuleRules
{
	public MyMusicGame(ReadOnlyTargetRules Target):base(Target)
	{
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "MediaAssets", "ImageWrapper" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
        //PublicIncludePaths.AddRange(new string[] { "MediaAssets/Public", "D:/Epic Games/UE_4.15/Engine/Source/Runtime/Launch/Public" });

        PrivateDependencyModuleNames.AddRange(new string[] { "HTTP" });
        PrivateIncludePathModuleNames.AddRange(new string[] { "HTTP" });

        PrivateIncludePaths.AddRange(new string[] { "/Source/Runtime/Launch/Private" });
        //AddEngineThirdPartyPrivateStaticDependencies(Target, "libcurl");

        // Uncomment if you are using Slate UI
        //if (UEBuildConfiguration.bBuildEditor == true)
        PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
