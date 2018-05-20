// JackMyth Personal

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "BPFunctionLib.generated.h"

/**
 * 
 */
UCLASS()
class MYMUSICGAME_API UBPFunctionLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable,Category="GameLogic_Static")
	static void ChangeScreenOrientation(bool ChangeToLandscape);
	UFUNCTION(BlueprintCallable, Category = "GameLogic_Static")
	static void GetFileMD5(const FString& FileName, bool& IsFileValid, FString& FileMD5);
	UFUNCTION(BlueprintCallable, Category = "GameLogic_Static")
	static void GetVideoGameInfo(FString MusicName,TArray<bool>& HaveVideo,TArray<FString>& VideoPath);
	UFUNCTION(BlueprintPure, Category = "GameLogic_Static")
		static FString GetVideoFilePath(FString VideoPath);
	UFUNCTION(BlueprintPure, Category = "GameLogic_Static")
		static bool IsScreenLandscape();
};

