// JackMyth Personal

using UnrealBuildTool;
using System.Collections.Generic;

public class MyMusicGameEditorTarget : TargetRules
{
	public MyMusicGameEditorTarget(TargetInfo Target):base(Target)
	{
		Type = TargetType.Editor;
		ExtraModuleNames.AddRange( new string[] { "MyMusicGame" } );
	}

	//
	// TargetRules interface.
	//

//	public override void SetupBinaries(
//		TargetInfo Target,
//		ref List<UEBuildBinaryConfiguration> OutBuildBinaryConfigurations,
//		ref List<string> OutExtraModuleNames
//		)
//	{
//		OutExtraModuleNames.AddRange( new string[] { "MyMusicGame" } );
//	}
}
