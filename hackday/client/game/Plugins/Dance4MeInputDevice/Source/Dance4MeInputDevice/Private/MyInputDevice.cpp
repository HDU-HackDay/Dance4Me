// JackMyth Personal

#include "MyInputDevice.h"
#include "ModuleManager.h"
#include <../InputDevice/Public/IInputDeviceModule.h>
#include <InputCoreTypes.h>
#include "WebsocketHolder.h"

#define LOCTEXT_NAMESPACE "FDance4MeInputDeviceModule"

namespace Dance4MeInputDevice
{
	const FKey Key1("Dance4Me_Key1");
	const FKey Key2("Dance4Me_Key2");
	const FKey Key3("Dance4Me_Key3");
	const FKey Key4("Dance4Me_Key4");
}

MyInputDevice::MyInputDevice(TSharedPtr< FGenericApplicationMessageHandler > mMessageHandler)
{
	MessageHandler = mMessageHandler;
	EKeys::AddKey(FKeyDetails(Dance4MeInputDevice::Key1, LOCTEXT("Dance4Me_Key1", "Dance4Me_Key1"), FKeyDetails::GamepadKey|FKeyDetails::FloatAxis));
	EKeys::AddKey(FKeyDetails(Dance4MeInputDevice::Key2, LOCTEXT("Dance4Me_Key2", "Dance4Me_Key2"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	EKeys::AddKey(FKeyDetails(Dance4MeInputDevice::Key3, LOCTEXT("Dance4Me_Key3", "Dance4Me_Key3"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
	EKeys::AddKey(FKeyDetails(Dance4MeInputDevice::Key4, LOCTEXT("Dance4Me_Key4", "Dance4Me_Key4"), FKeyDetails::GamepadKey | FKeyDetails::FloatAxis));
}

MyInputDevice::~MyInputDevice()
{
}

void MyInputDevice::Tick(float DeltaTime)
{
}

void MyInputDevice::SendControllerEvents()
{
	auto* pHolder = GetMutableDefault<UWebsocketHolder>();
	for (int i=0;i<4;i++)
	{
		if (pHolder->IsButtonPressing(i))
		{
			pHolder->SetButtonPressing(i, false);
			FName TargetKeyName;
			switch (i)
			{
				case 0:
					TargetKeyName = Dance4MeInputDevice::Key1.GetFName();
					pHolder->Key1.ExecuteIfBound();
				break;
				case 1:
					TargetKeyName = Dance4MeInputDevice::Key2.GetFName();
					pHolder->Key2.ExecuteIfBound();
					break;
				case 2:
					TargetKeyName = Dance4MeInputDevice::Key3.GetFName();
					pHolder->Key3.ExecuteIfBound();
					break;
				case 3:
					TargetKeyName = Dance4MeInputDevice::Key4.GetFName();
					pHolder->Key4.ExecuteIfBound();
					break;
			}/*
			if (KeyPressing[i])
			{
				MessageHandler->OnControllerButtonPressed(TargetKeyName, 0, true);

			}
			else
			{
				MessageHandler->OnControllerButtonReleased(TargetKeyName, 0, true);
			}*/
			MessageHandler->OnControllerAnalog(TargetKeyName, 0, KeyPressing[i] ? 1 : 0);
		}
	}
}

void MyInputDevice::SetMessageHandler(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	MessageHandler = InMessageHandler;
}

bool MyInputDevice::Exec(UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar)
{
	return true;
}

void MyInputDevice::SetChannelValue(int32 ControllerId, FForceFeedbackChannelType ChannelType, float Value)
{
	
}

void MyInputDevice::SetChannelValues(int32 ControllerId, const FForceFeedbackValues &values)
{
	
}

#undef LOCTEXT_NAMESPACE