// JackMyth Personal

#include "WebsocketHolder.h"
#include "MessageDialog.h"
#include "WebSocketBlueprintLibrary.h"
#include "Dance4MeInputDevice.h"
#include "JsonReader.h"
//#include "UWorld.h"

void UWebsocketHolder::OnDataReceived(const FString& DataStr)
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "DD");
	TSharedRef<TJsonReader<TCHAR>> ResultJsonReader = TJsonReaderFactory<TCHAR>::Create(DataStr);
	TSharedPtr<FJsonObject> JsonParsed = MakeShareable(new FJsonObject());
	FJsonSerializer::Deserialize(ResultJsonReader, JsonParsed);
	FString TypeStr = JsonParsed->GetStringField("type");
	if (TypeStr=="hard")
	{
		auto DataField = JsonParsed->GetObjectField("data");
		int cid = DataField->GetIntegerField("cid");
		bool status = JsonParsed->GetIntegerField("status") > 0 ? true : false;
		ButtonPressing[cid-1] = status;
	}
	else if (TypeStr=="heart")
	{
		auto heartbeat = JsonParsed->GetNumberField("heartbeat");
		auto breath = JsonParsed->GetNumberField("breath");
		HeartArray.RemoveAt(0);
		LastHeartBeat = heartbeat + HeartOffset;
		HeartArray.Add(LastHeartBeat);
		BreathArray.RemoveAt(0);
		LastBreath = breath + HeartOffset;
		BreathArray.Add(LastBreath);
	}
}

void UWebsocketHolder::OnClosed()
{
	TryConnect(tmpUObject, LastURi);
}



void UWebsocketHolder::TryConnect(const UObject* WCO, FString URi)
{
	GetMutableDefault<UWebsocketHolder>()->tmpUObject = (UObject*)WCO;
	GetMutableDefault<UWebsocketHolder>()->LastURi = URi;
	GetMutableDefault<UWebsocketHolder>()->HeartArray.SetNum(256);
	GetMutableDefault<UWebsocketHolder>()->BreathArray.SetNum(256);
	FDance4MeInputDeviceModule& x = FModuleManager::GetModuleChecked<FDance4MeInputDeviceModule>("Dance4MeInputDevice");
	x.WebsocketBaseInstance = UWebSocketBlueprintLibrary::Connect(URi/*"ws://192.168.0.102:3000"*/);
	x.WebsocketBaseInstance->OnReceiveData.AddUniqueDynamic(GetMutableDefault<UWebsocketHolder>(), &UWebsocketHolder::OnDataReceived);
	x.WebsocketBaseInstance->OnClosed.AddUniqueDynamic(GetMutableDefault<UWebsocketHolder>(), &UWebsocketHolder::OnClosed);
	GetMutableDefault<UWebsocketHolder>()->AddToRoot();
	FTimerHandle TimerHandle;
	WCO->GetWorld()->GetTimerManager().ClearAllTimersForObject(GetMutableDefault<UWebsocketHolder>());
	WCO->GetWorld()->GetTimerManager().SetTimer(TimerHandle, GetMutableDefault<UWebsocketHolder>(), &UWebsocketHolder::ExplandHeartGraph, 0.02, true,0.02);
}

void UWebsocketHolder::Reconnect()
{
	FDance4MeInputDeviceModule& x = FModuleManager::GetModuleChecked<FDance4MeInputDeviceModule>("Dance4MeInputDevice");
	x.WebsocketBaseInstance->Close();
	TryConnect(tmpUObject,LastURi);
}

void UWebsocketHolder::ExplandHeartGraph()
{
	auto* pHolder = GetMutableDefault<UWebsocketHolder>();
	pHolder->HeartArray.RemoveAt(0);
	pHolder->HeartArray.Add(LastHeartBeat +HeartOffset);
	pHolder->BreathArray.RemoveAt(0);
	pHolder->BreathArray.Add(LastBreath + HeartOffset);
}

TArray<float> UWebsocketHolder::GetHeartBeat()
{
	return GetMutableDefault<UWebsocketHolder>()->HeartArray;
}

TArray<float> UWebsocketHolder::GetBreath()
{
	return GetMutableDefault<UWebsocketHolder>()->BreathArray;
}

void UWebsocketHolder::BindKeyAction(FDance4MeKey DanceKeyDelegate, int KeyValue)
{
	auto* pHolder = GetMutableDefault<UWebsocketHolder>();
	switch (KeyValue)
	{
		case 1:
			pHolder->Key1 = DanceKeyDelegate;
			break;
		case 2:
			pHolder->Key2 = DanceKeyDelegate;
			break;
		case 3:
			pHolder->Key3 = DanceKeyDelegate;
			break;
		case 4:
			pHolder->Key4 = DanceKeyDelegate;
			break;
	}
}

void UWebsocketHolder::SetHeartBeatOffset(float Offset)
{
	GetMutableDefault<UWebsocketHolder>()->HeartOffset = Offset;
}

UWebsocketHolder::~UWebsocketHolder()
{
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::White, "WebsocketHolder Destroyed!");
	FDance4MeInputDeviceModule& x = FModuleManager::GetModuleChecked<FDance4MeInputDeviceModule>("Dance4MeInputDevice");
}
