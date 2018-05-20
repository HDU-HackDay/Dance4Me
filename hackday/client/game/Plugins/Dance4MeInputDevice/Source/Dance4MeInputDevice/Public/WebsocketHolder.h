// JackMyth Personal

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "WebsocketHolder.generated.h"

DECLARE_DYNAMIC_DELEGATE(FDance4MeKey);


/**
 * 
 */
UCLASS()
class DANCE4MEINPUTDEVICE_API UWebsocketHolder : public UObject
{
	GENERATED_BODY()
	bool ButtonPressing[4] = { false };
	FString LastURi;
	UObject* tmpUObject;
	TArray<float> HeartArray;
	TArray<float> BreathArray;
	float HeartOffset = 0;
	float LastHeartBeat = 0;
	float LastBreath = 0;
public:
	FDance4MeKey Key1, Key2, Key3, Key4;
	UFUNCTION()
		void OnDataReceived(const FString& DataStr);
	UFUNCTION()
		void OnClosed();
	UFUNCTION(BlueprintCallable,meta=(WorldContext="WCO"))
		static void TryConnect(const UObject* WCO, FString URi);
	inline bool IsButtonPressing(int ButtonID)
	{
		return ButtonPressing[ButtonID];
	}

	inline void SetButtonPressing(int ButtonID, bool IsPressing)
	{
		ButtonPressing[ButtonID]=IsPressing;
	}

	UFUNCTION()
		void Reconnect();

	UFUNCTION()
		void ExplandHeartGraph();

	UFUNCTION(BlueprintCallable)
		static TArray<float> GetHeartBeat();

	UFUNCTION(BlueprintCallable)
		static TArray<float> GetBreath();

	UFUNCTION(BlueprintCallable)
	static void BindKeyAction(FDance4MeKey DanceKeyDelegate,int KeyValue);
	
	UFUNCTION(BlueprintCallable)
		static void SetHeartBeatOffset(float Offset);
	virtual ~UWebsocketHolder();
};
