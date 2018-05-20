// JackMyth Personal

#include "MyMusicGame.h"
#include "BPFunctionLib.h"
#if PLATFORM_ANDROID
//#include "D:/Epic Games/UE_4.15/Engine/Source/Runtime/Launch/Public/Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidJNI.h"
#endif

void UBPFunctionLib::ChangeScreenOrientation(bool ChangeToLandscape)
{
#if PLATFORM_ANDROID
	JNIEnv* JE = FAndroidApplication::GetJavaEnv();
	if (!JE)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Get JNI Environment Faild,Null is Returned"));
		return;
	}
	jmethodID SetOrientationID = FJavaWrapper::FindMethod(JE, FJavaWrapper::GameActivityClassID, "setRequestedOrientation", "(I)V", false);
	if (!SetOrientationID)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Red, TEXT("Find MethoudID Faild,Null is Returned"));
		return;
	}
	FVector2D ViewportSize = GEngine->GameViewport->GetWindow()->GetViewportSize();
	if (ChangeToLandscape&&ViewportSize.Y > ViewportSize.X)
		FJavaWrapper::CallVoidMethod(JE, FJavaWrapper::GameActivityThis, SetOrientationID, 0);
	else if (!ChangeToLandscape&&ViewportSize.X > ViewportSize.Y)
		FJavaWrapper::CallVoidMethod(JE, FJavaWrapper::GameActivityThis, SetOrientationID, 1);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("Platform_Android,JNI has been Called"));
#else
	FVector2D ViewportSize= GEngine->GameViewport->GetWindow()->GetViewportSize();
	if (ChangeToLandscape&&ViewportSize.Y > ViewportSize.X)
		GEngine->GameViewport->GetWindow()->Resize(FVector2D(ViewportSize.Y, ViewportSize.X));
	else if (!ChangeToLandscape&&ViewportSize.X > ViewportSize.Y)
		GEngine->GameViewport->GetWindow()->Resize(FVector2D(ViewportSize.Y, ViewportSize.X));
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, TEXT("JNI has not been Called"));
#endif
}

void UBPFunctionLib::GetFileMD5(const FString& FileName,bool& IsFileValid, FString& FileMD5)
{
	if (!IFileManager::Get().FileExists(*FileName))
	{
		IsFileValid = false;
		return;
	}
	char HexMask[] = { '0', '1', '2', '3', '4', '5',
		'6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	//FString DownloadPath = FPaths::GamePersistentDownloadDir();
	FMD5Hash hash= FMD5Hash::HashFile(*(FileName));
	const uint8* HashByte = hash.GetBytes();
	char TmpMD5[33] = {0};
	for (int i=0;i<16;i++)
	{
		TmpMD5[2 * i] = HexMask[HashByte[i] >> 4];
		TmpMD5[2 * i+1] = HexMask[HashByte[i] & 0x0f];
	}
	FileMD5 = FString(TmpMD5);
	IsFileValid = true;
	return;
}

void UBPFunctionLib::GetVideoGameInfo(FString MusicNameF, TArray<bool>& HaveVideo, TArray<FString>& VideoPath)
{
	TArray<FString> FileContent;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::GameContentDir() + "/MyMusicGame/MusicData/" + MusicNameF), NULL, FileContent);
	if (FileContent.Num()>9&&FileContent[9]!="")
	{
		char AC[3][256];
		sscanf(TCHAR_TO_ANSI(*FileContent[9]), "%[^*]*%[^*]*%s", AC[0], AC[1], AC[2]);
		for (int i = 0; i < 3; i++)
		{
			if (!strcmp(AC[i],"Null"))
			{
				HaveVideo.Add(false);
				VideoPath.Add("");
			}
			else
			{
				HaveVideo.Add(true);
				VideoPath.Add(AC[i]);
			}
		}
	}
}

FString UBPFunctionLib::GetVideoFilePath(FString VideoPath)
{
	return FPaths::GamePersistentDownloadDir() + TEXT("/GameVideo/") + VideoPath;
}

bool UBPFunctionLib::IsScreenLandscape()
{
	FVector2D ViewportSize = GEngine->GameViewport->GetWindow()->GetViewportSize();
	return ViewportSize.Y < ViewportSize.X;
}