// JackMyth Personal

#include "MyMusicGame.h"
#include "FunctionLibrary.h"
#include "FileManagerGeneric.h"
//#include "D:/Epic Games/UE_4.15/Engine/Source/Developer/TargetPlatform/Public/Interfaces/IAudioFormat.h"
#include "../TargetPlatform/Public/Interfaces/IAudioFormat.h"
#include "Runtime/ImageWrapper/Public/IImageWrapperModule.h"
#include "Runtime/ImageWrapper/Public/IImageWrapper.h"
#include "VorbisAudioInfo.h"
#include "Audio.h"
#include "ActiveSound.h"
#include "AudioDevice.h"
#include <locale.h>
#include <string>
#include "StringConv.h"
#if PLATFORM_ANDROID
#include "../Launch/Public/Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#endif
//


// Sets default values
AFunctionLibrary::AFunctionLibrary()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	//MP = ConstructorHelpers::FObjectFinder<UMediaPlayer>(TEXT("MediaPlayer'/Game/MyMusicGame/Resources/MusicMediaPlayer.MusicMediaPlayer'")).Object;
}

// Called when the game starts or when spawned
void AFunctionLibrary::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AFunctionLibrary::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//MusicTime = MP->GetTime().GetTotalMinutes();
	//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FString::SanitizeFloat(MusicTime));
}

TArray<FString> AFunctionLibrary::GetMusicList(FString TargetCollection)
{
	TArray<FString> FileNameList;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + TargetCollection), NULL, FileNameList);
	return FileNameList;
}

TArray<FRhythmData> AFunctionLibrary::GetMusicRhythmNotes(FString MusicName,int MusicLevel)
{
	TArray<FRhythmData> FRD;
	TArray<FString> FileContent;
	FString FilePath;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileContent);
	if (FileContent[MusicLevel + 3] == "Null")
		return FRD;
	FilePath = FileContent[MusicLevel + 3];
	FileContent.Empty();
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicResource/" + FilePath), NULL, FileContent);
	//if (FileContent[FileContent.Num()-1]=="")
	FileContent.Remove("");
	FRhythmData TmpFRD;
	for (int i=0;i<FileContent.Num();i++)
	{
		swscanf(*FileContent[i], TEXT("%d,%d,%d"), &TmpFRD.Time, &TmpFRD.Position, &TmpFRD.Type);
		FRD.Add(TmpFRD);
	}
	FRD.Sort([](const FRhythmData& LHS, const FRhythmData& RHS) {return LHS.Time < RHS.Time; });
	return FRD;
}

FString AFunctionLibrary::GetMusicFilePath(FString MusicName,  int MusicLevel)
{
	TArray<FString> FileContent;
	FString FPath;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileContent);
	if (FileContent.Num() >= 3)
	{
		if (FileContent[2].Contains("*"))
		{
			char AC[3][200];
			sscanf(TCHAR_TO_ANSI(*FileContent[2]), "%[^*]*%[^*]*%s", AC[0], AC[1], AC[2]);
			FPath = FString(AC[MusicLevel]);
		}
		else
			FPath = FileContent[2];
		GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, FPath);
		return FPaths::ProjectContentDir() + "/MyMusicGame/MusicResource/" + FPath;
	}
	else
		return FString("");
}

UTexture2D* AFunctionLibrary::GetMusicAlbumPic(FString MusicName)
{
	TArray<FString> FileContent;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileContent);
	return GetLocalTexture(FPaths::ProjectContentDir() + "/MyMusicGame/MusicResource/" + FileContent[6]);
}

void AFunctionLibrary::GetMusicTime(UAudioComponent* UA)
{
	//GEngine->AddOnScreenDebugMessage(-1,5,FColor::Green, FString::SanitizeFloat(UA->GetAudioDevice()->GetAudioClock()));
}

float AFunctionLibrary::GetMusicPreviewStart(FString MusicName)
{
	TArray<FString> FileContent;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileContent);
	return FCString::Atof(*FileContent[7]);
}

float AFunctionLibrary::GetMusicPreviewLength(FString MusicName)
{
	TArray<FString> FileContent;
	FFileHelper::LoadANSITextFileToStrings(*(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileContent);
	return FCString::Atof(*FileContent[8])- FCString::Atof(*FileContent[6]);
}

FString AFunctionLibrary::GetMusicName(FString MusicName)
{
	//TArray<FString> FileC;
	TArray<uint8> R;
	TCHAR TC[1024] = { 0 };
	char MusicianA[1024];
	//FFileHelper::LoadANSITextFileToStrings(*(FPaths::GameContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileC);
	FFileHelper::LoadFileToArray(R, *(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName));
	sscanf((char*)R.GetData(), "%[^\r]", MusicianA);
	CharToTChar(TC, MusicianA);
	return FString(TC);
}

FString AFunctionLibrary::GetMusicianName(FString MusicName)
{
	//TArray<FString> FileC;
	TArray<uint8> R;
	TCHAR TC[1024] = {0};
	char MusicianA[1024];
	//FFileHelper::LoadANSITextFileToStrings(*(FPaths::GameContentDir() + "/MyMusicGame/MusicData/" + MusicName), NULL, FileC);
	FFileHelper::LoadFileToArray(R, *(FPaths::ProjectContentDir() + "/MyMusicGame/MusicData/" + MusicName));
	sscanf((char*)R.GetData(), "%*[^\r]\r\n%[^\r]", MusicianA);
	CharToTChar(TC, MusicianA);
	return FString(TC);
}

USoundWave* AFunctionLibrary::GetSoundWaveByLocal(const FString& MusicFileName)
{
	//GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FPaths::GameContentDir() + "/MyMusicGame/MusicData/" + MusicFileName);
	return GetSoundWaveFromFile(FPaths::ProjectContentDir() + "/MyMusicGame/MusicResource/" + MusicFileName);
}

USoundWave* AFunctionLibrary::GetSoundWaveFromFile(const FString& FilePath)
{
	USoundWave* sw = NewObject<USoundWave>(USoundWave::StaticClass());
	if (!sw)
		return NULL;
	//* If true the song was successfully loaded
	bool loaded = false;
	//* loaded song file (binary, encoded)
	TArray < uint8 > rawFile;
	loaded = FFileHelper::LoadFileToArray(rawFile, FilePath.GetCharArray().GetData());
	if (loaded)
	{
		FByteBulkData* bulkData = &sw->CompressedFormatData.GetFormat(TEXT("OGG"));
		bulkData->Lock(LOCK_READ_WRITE);
		FMemory::Memcpy(bulkData->Realloc(rawFile.Num()), rawFile.GetData(), rawFile.Num());
		bulkData->Unlock();
		loaded = fillSoundWaveInfo(sw, &rawFile) == 0 ? true : false;
	}
	if (!loaded)
		return NULL;
	sw->bVirtualizeWhenSilent = true;
	return sw;
}

int32 AFunctionLibrary::fillSoundWaveInfo(class USoundWave* sw, TArray<uint8>* rawFile)
{
	FSoundQualityInfo info;
	FVorbisAudioInfo vorbis_obj;
	if (!vorbis_obj.ReadCompressedInfo(rawFile->GetData(), rawFile->Num(), &info))
	{
		//Debug("Can't load header");
		return 1;
	}

	if (!sw) return 1;
	sw->SoundGroup = ESoundGroup::SOUNDGROUP_Default;
	sw->NumChannels = info.NumChannels;
	sw->Duration = info.Duration;
	sw->RawPCMDataSize = info.SampleDataSize;
	sw->SampleRate = info.SampleRate;
	return 0;
}


int32 AFunctionLibrary::findSource(class USoundWave* sw, class FSoundSource* out_audioSource)
{
	FAudioDevice* device = GEngine ? GEngine->GetMainAudioDevice() : NULL; //gently ask for the audio device

	FActiveSound* activeSound;
	FSoundSource* audioSource;
	FWaveInstance* sw_instance;
	if (!device)
	{
		activeSound = NULL;
		audioSource = NULL;
		out_audioSource = audioSource;
		return -1;
	}

	TArray<FActiveSound*> tmpActualSounds = device->GetActiveSounds();
	if (tmpActualSounds.Num())
	{
		for (auto activeSoundIt(tmpActualSounds.CreateIterator()); activeSoundIt; ++activeSoundIt)
		{
			activeSound = *activeSoundIt;
			for (auto WaveInstanceIt(activeSound->WaveInstances.CreateIterator()); WaveInstanceIt; ++WaveInstanceIt)
			{
				sw_instance = WaveInstanceIt.Value();
				if (sw_instance->WaveData->CompressedDataGuid == sw->CompressedDataGuid)
				{
					audioSource = device->GetSoundSource(sw_instance); //4.13 onwards, <3 Rama
					out_audioSource = audioSource;
					return 0;
				}
			}
		}
	}

	audioSource = NULL;
	activeSound = NULL;
	out_audioSource = audioSource;
	return -2;
}

UTexture2D* AFunctionLibrary::GetLocalTexture(const FString &_TexPath)
{
	UTexture2D* OutTex = NULL;
	IImageWrapperModule& imageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> imageWrapper = imageWrapperModule.CreateImageWrapper(EImageFormat::JPEG);
	TArray<uint8> OutArray;
	if (FFileHelper::LoadFileToArray(OutArray, *_TexPath))
	{
		if (imageWrapper.IsValid() &&
			imageWrapper->SetCompressed(OutArray.GetData(), OutArray.Num()))
		{
			const TArray<uint8>* uncompressedRGBA = NULL;
			if (imageWrapper->GetRaw(ERGBFormat::RGBA, 8, uncompressedRGBA))
			{
				const TArray<FColor> uncompressedFColor = uint8ToFColor(*uncompressedRGBA);
				OutTex = TextureFromImage(
					imageWrapper->GetWidth(),
					imageWrapper->GetHeight(),
					uncompressedFColor,
					true);
			}
		}
	}
	return OutTex;
}

TArray<FColor> AFunctionLibrary::uint8ToFColor(const TArray<uint8> origin)
{
	TArray<FColor> uncompressedFColor;
	uint8 auxOrigin;
	FColor auxDst;

	for (int i = 0; i < origin.Num(); i++) {
		auxOrigin = origin[i];
		auxDst.B = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.G = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.R = auxOrigin;
		i++;
		auxOrigin = origin[i];
		auxDst.A = auxOrigin;
		uncompressedFColor.Add(auxDst);
	}

	return uncompressedFColor;
}

UTexture2D* AFunctionLibrary::TextureFromImage(const int32 SrcWidth, const int32 SrcHeight, const TArray<FColor>&SrcData, const bool UseAlpha)
{

	//创建Texture2D纹理
	UTexture2D* MyScreenshot = UTexture2D::CreateTransient(SrcWidth, SrcHeight, PF_B8G8R8A8);

	//锁住他的数据,以便修改
	uint8* MipData = static_cast<uint8*>(MyScreenshot->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE));

	//创建纹理数据
	uint8* DestPtr = NULL;
	const FColor* SrcPtr = NULL;
	for (int32 y = 0; y < SrcHeight; y++)
	{
		DestPtr = &MipData[(SrcHeight - 1 - y)*SrcWidth * sizeof(FColor)];
		SrcPtr = const_cast<FColor*>(&SrcData[(SrcHeight - 1 - y)*SrcWidth]);
		for (int32 x = 0; x < SrcWidth; x++)
		{
			*DestPtr++ = SrcPtr->B;
			*DestPtr++ = SrcPtr->G;
			*DestPtr++ = SrcPtr->R;
			if (UseAlpha)
			{
				*DestPtr++ = SrcPtr->A;
			}
			else
			{
				*DestPtr++ = 0xFF;
			}
			SrcPtr++;
		}
	}

	//解锁纹理
	MyScreenshot->PlatformData->Mips[0].BulkData.Unlock();
	MyScreenshot->UpdateResource();
	return MyScreenshot;
}

void AFunctionLibrary::GetScoresFromInternet(FString MusicNameL,FOnRankArrived RankArrived)
{
	TSharedPtr<IHttpRequest> HRequest;
	HRequest = FHttpModule::Get().CreateRequest();
	HRequest->SetURL(FString("Https://jackmyth.cn/GameInterface/MYMusicGame/GetRank.php?MusicNameL=")+MusicNameL);
	HRequest->OnProcessRequestComplete().BindUObject(this, &AFunctionLibrary::OnRankResponseReceived);
	OnRankArrivedDelegate.BindUFunction(RankArrived.GetUObject(), RankArrived.GetFunctionName());
	HRequest->ProcessRequest();
}

void AFunctionLibrary::OnRankResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	FString Contents;
	TArray<uint8> Chars;
	TArray<FString> TmpStringLine;
	TArray<FString> PName;
	TArray<FString> PScore;
	TCHAR TC[2048];
	if (!bWasSuccessful)
	{
		OnRankArrivedDelegate.Execute(PName, PScore, bWasSuccessful);
		return;
	}
	Chars = Response->GetContent();
	Chars.Add(0);
	CharToTChar(TC, (char*)Chars.GetData());
	Contents = FString(TC);
	Contents.ParseIntoArrayLines(TmpStringLine);
	for (FString StrLine:TmpStringLine)
	{
		PName.Add("");
		PScore.Add("");	
		StrLine.Split(" ", &PName[PName.Num() - 1], &PScore[PScore.Num() - 1]);
	}
	OnRankArrivedDelegate.Execute(PName, PScore, bWasSuccessful);
}

bool AFunctionLibrary::PostScoreToInternet(FString MusicNameL, FString PlayerName, float ScoreToPost, FNotifyDelegate OnScorePosted)
{
	TSharedPtr<IHttpRequest> HRequest;
	HRequest = FHttpModule::Get().CreateRequest(); 
	char Chr[10];
	sprintf(Chr, "%.2f", ScoreToPost);
	//PlayerName = FString(TCHAR_TO_UTF8(*PlayerName));
	HRequest->SetURL(FString("Https://jackmyth.cn/GameInterface/MYMusicGame/PostScore.php?MusicNameL=") + MusicNameL + TEXT("&PlayerName=") + FPlatformHttp::UrlEncode(PlayerName) + TEXT("&Score=") + Chr);
	//HRequest->OnProcessRequestComplete().BindUFunction(OnScorePosted.GetUObject(), OnScorePosted.GetFunctionName());
	OnScorePostedDelegate.BindUFunction(OnScorePosted.GetUObject(), OnScorePosted.GetFunctionName());
	HRequest->OnProcessRequestComplete().BindUObject(this, &AFunctionLibrary::OnScoreRespond);
	return HRequest->ProcessRequest();
}

void AFunctionLibrary::OnScoreRespond(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	OnScorePostedDelegate.ExecuteIfBound();
}

bool AFunctionLibrary::CheckUpdate(FOnUpdateArrived OnUpdateArrived)
{
	FString ProjectVersion;
	TSharedPtr<IHttpRequest> HRequest;
	HRequest = FHttpModule::Get().CreateRequest();
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		ProjectVersion,
		GGameIni
	);
	int Ver[4];
	swscanf(*ProjectVersion, TEXT("%d.%d.%d.%d"), &Ver[0], &Ver[1], &Ver[2], &Ver[3]);
	HRequest->SetURL(FString("Https://jackmyth.cn/GameInterface/MYMusicGame/CheckNewVersion.php?Version=") + FString::FromInt(Ver[0]*1000+Ver[1]*100+Ver[2]*10+Ver[3]));
	HRequest->OnProcessRequestComplete().BindUObject(this, &AFunctionLibrary::OnCUpdateResponseReceived);
	OnUpdateArrivedDelegate.BindUFunction(OnUpdateArrived.GetUObject(), OnUpdateArrived.GetFunctionName());
	return HRequest->ProcessRequest();
}

void AFunctionLibrary::OnCUpdateResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (!bWasSuccessful)
		return;
	if (Response->GetContentAsString()	=="NoUpdate")
	{
		OnUpdateArrivedDelegate.Execute(false,TEXT(""),"");
	}
	else 
	{
		TCHAR TC[1024];
		TArray<uint8> TAUint = Response->GetContent();
		TAUint.Add(0);
		CharToTChar(TC,(char*)TAUint.GetData());
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, Response->GetContentAsString());
		OnUpdateArrivedDelegate.Execute(true,FString(TC),TEXT("Https://jackmyth.cn/GameInterface/MYMusicGame/GetNewVersion.php"));
	}
}

void AFunctionLibrary::CharToTChar(TCHAR* Tchar, char* Char)
{
	/*if (!setlocale(LC_ALL, "zh_CN.GBK")&& !setlocale(LC_ALL, ""))
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("SetLocaleFaild"));
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, setlocale(LC_ALL, ""));
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, setlocale(LC_ALL, "zh_CN.GBK"));
	}*/
	wcscpy(Tchar, UTF8_TO_TCHAR(Char));
	//swprintf(Tchar,1024, TEXT("%S"), Char);
}

void AFunctionLibrary::CallSendEMail()
{
	FPlatformProcess::LaunchURL(TEXT("mailto:wwwbkkk@126.com"), NULL, NULL);
}

void AFunctionLibrary::GetProjectVersion(FString& VersionStr, int& VersionNumber)
{
	GConfig->GetString(
		TEXT("/Script/EngineSettings.GeneralProjectSettings"),
		TEXT("ProjectVersion"),
		VersionStr,
		GGameIni
	);
	int Ver[4];
	swscanf(*VersionStr, TEXT("%d.%d.%d.%d"), &Ver[0], &Ver[1], &Ver[2], &Ver[3]);
	VersionNumber = Ver[0] * 1000 + Ver[1] * 100 + Ver[2] * 10 + Ver[3];
}

void AFunctionLibrary::DownloadFromURL(const FString& URL, const FString& DestName,FDownloadNotify DownloadNotifyDelegate)
{
	TSharedPtr<IHttpRequest> HRequest;
	HRequest = FHttpModule::Get().CreateRequest();
	HRequest->SetURL(URL);
	//HRequest->OnProcessRequestComplete().BindUFunction(OnScorePosted.GetUObject(), OnScorePosted.GetFunctionName());
	OnDownloadNotifyDelegate.BindUFunction(DownloadNotifyDelegate.GetUObject(), DownloadNotifyDelegate.GetFunctionName());
	//HRequest->OnRequestProgress().BindUObject(this, &AFunctionLibrary::DownloaderNotify);
	HRequest->OnRequestProgress().BindLambda([this](FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived) 
	{
		if (Request->GetResponse().IsValid())
			OnDownloadNotifyDelegate.ExecuteIfBound(BytesReceived, Request->GetResponse()->GetContentLength(), false);
	});
	HRequest->OnProcessRequestComplete().BindUObject(this, &AFunctionLibrary::DownloadFinished);
	DownloadDestName = DestName;
	HRequestGlobal = HRequest;
	HRequest->ProcessRequest();
}

void AFunctionLibrary::DownloaderNotify(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived)
{
	OnDownloadNotifyDelegate.ExecuteIfBound(BytesReceived, Request->GetContentLength(), false);
}

void AFunctionLibrary::DownloadFinished(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	if (bWasSuccessful)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20, FColor::Green,FPaths::GamePersistentDownloadDir() + "\\" + DownloadDestName);
		FFileHelper::SaveArrayToFile(Response->GetContent(), *(FPaths::GamePersistentDownloadDir() + "\\" + DownloadDestName));
		OnDownloadNotifyDelegate.ExecuteIfBound(Response->GetContentLength(), Request->GetContentLength(), true);
	}
	else
		OnDownloadNotifyDelegate.ExecuteIfBound(-1, Request->GetContentLength(), true);
}

void AFunctionLibrary::CancelDownlaod()
{
	if (HRequestGlobal.IsValid())
	{
		HRequestGlobal->CancelRequest();
		HRequestGlobal = NULL;
	}
}

void AFunctionLibrary::GetVideoInfo(FString VideoPath, FGetVideoInfoDelegate Delegate)
{
	TSharedPtr<IHttpRequest> HRequest;
	HRequest = FHttpModule::Get().CreateRequest();
	HRequest->SetURL(TEXT("http://115.159.152.245/GameInterface/MYMusicGame/VideoInfo/")+VideoPath + TEXT(".html"));
	HRequest->OnProcessRequestComplete().BindLambda(
		[this, Delegate](FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
		{
			FString VideoInfoContent;
			VideoInfoContent = Response->GetContentAsString();
			char VideoInfoSplited[3][500];
			sscanf(TCHAR_TO_ANSI(*VideoInfoContent), "%s%s%s", VideoInfoSplited[0], VideoInfoSplited[1], VideoInfoSplited[2]);
			Delegate.ExecuteIfBound(bWasSuccessful, VideoInfoSplited[0], VideoInfoSplited[1], VideoInfoSplited[2]);
		});
	HRequest->ProcessRequest();
}