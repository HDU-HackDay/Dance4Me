// JackMyth Personal

#pragma once

#include "GameFramework/Actor.h"
#include "StructureLibrary.h"
#include "Http.h"
#include "FunctionLibrary.generated.h"

DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnRankArrived,const TArray<FString>&, PlayerNames,const TArray<FString>&, PlayerScore, bool, IsSuccessful);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FOnUpdateArrived,bool,ShouldUpdate,FString,UpdateInfomation,FString,UpdateURL);
DECLARE_DYNAMIC_DELEGATE(FNotifyDelegate);
DECLARE_DYNAMIC_DELEGATE_ThreeParams(FDownloadNotify,int32,ByteReceived,int32,ContentLength,bool,DownloadFinished);
DECLARE_DYNAMIC_DELEGATE_FourParams(FGetVideoInfoDelegate,bool, IsSuccessful, FString, VideoSize, FString, VideoMD5Hash, FString, DownloadURL);

UCLASS()
class MYMUSICGAME_API AFunctionLibrary : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFunctionLibrary();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(BlueprintReadOnly)
		float MusicTime = 0;
	UFUNCTION(BlueprintCallable, Category="GameLogic")
		TArray<FString> GetMusicList(FString TargetCollection);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		FString GetMusicianName(FString MusicName);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		FString GetMusicName(FString MusicName);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		TArray<FRhythmData> GetMusicRhythmNotes(FString MusicName,int MusicLevel);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		FString GetMusicFilePath(FString MusicName, int MusicLevel=0);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		USoundWave* GetSoundWaveByLocal(const FString& MusicFileName);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		USoundWave* GetSoundWaveFromFile(const FString& FilePath);
	int32 findSource(class USoundWave* sw, class FSoundSource* out_audioSource);
	int32 fillSoundWaveInfo(class USoundWave* sw, TArray<uint8>* rawFile);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void GetMusicTime(UAudioComponent* UA);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		float GetMusicPreviewStart(FString MusicName);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		float GetMusicPreviewLength(FString MusicName);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		UTexture2D* GetMusicAlbumPic(FString MusicName);
	UTexture2D* GetLocalTexture(const FString &_TexPath);
	TArray<FColor> uint8ToFColor(const TArray<uint8> origin);
	UTexture2D* TextureFromImage(const int32 SrcWidth, const int32 SrcHeight, const TArray<FColor>&SrcData, const bool UseAlpha);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void GetScoresFromInternet(FString MusicNameL,FOnRankArrived RankArrived);
	void OnRankResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	void OnCUpdateResponseReceived(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
	UPARAM(DisplayName="SuccessulPost")
		bool PostScoreToInternet(FString MusicNameL,FString PlayerName,float ScoreToPost, FNotifyDelegate OnScorePosted);
	FOnRankArrived OnRankArrivedDelegate;
	FOnUpdateArrived OnUpdateArrivedDelegate;
	FNotifyDelegate OnScorePostedDelegate;
	FDownloadNotify OnDownloadNotifyDelegate;
	FString DownloadDestName;
	void CharToTChar(TCHAR* Tchar, char* Char);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		bool CheckUpdate(FOnUpdateArrived OnUpdateArrived);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void CallSendEMail();
	void OnScoreRespond(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	UFUNCTION(BlueprintCallable,Category="GameLogic")
		void GetProjectVersion(FString& VersionStr, int& VersionNumber);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void DownloadFromURL(const FString& URL,const FString& DestName,FDownloadNotify DownloadNotifyDelegate);
	TSharedPtr<IHttpRequest> HRequestGlobal;
	void DownloaderNotify(FHttpRequestPtr Request, int32 BytesSent, int32 BytesReceived);
	void DownloadFinished(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void CancelDownlaod();
	UFUNCTION(BlueprintCallable, Category = "GameLogic")
		void GetVideoInfo(FString VideoPath, FGetVideoInfoDelegate Delegate);
};