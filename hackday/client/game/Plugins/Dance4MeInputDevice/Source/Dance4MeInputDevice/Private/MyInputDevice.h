// JackMyth Personal

#pragma once

#include "CoreMinimal.h"
#include <../InputDevice/Public/IInputDevice.h>

/**
 * 
 */
class MyInputDevice :public IInputDevice
{
	TSharedPtr< FGenericApplicationMessageHandler > MessageHandler;
	bool KeyPressing[4] = { false };
public:
	MyInputDevice(TSharedPtr< FGenericApplicationMessageHandler > mMessageHandler);
	~MyInputDevice();

	virtual void Tick(float DeltaTime) override;


	virtual void SendControllerEvents() override;


	virtual void SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override;


	virtual bool Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar) override;


	virtual void SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value) override;


	virtual void SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values) override;

};
