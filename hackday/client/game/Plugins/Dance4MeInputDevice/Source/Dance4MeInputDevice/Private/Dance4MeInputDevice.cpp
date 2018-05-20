// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Dance4MeInputDevice.h"
#include "MessageDialog.h"
#include "WebsocketHolder.h"
#include "WebSocketBlueprintLibrary.h"
#include "MyInputDevice.h"
#include <IPAddress.h>
#include <SocketSubsystem.h>

#define LOCTEXT_NAMESPACE "FDance4MeInputDeviceModule"

void FDance4MeInputDeviceModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	IInputDeviceModule::StartupModule();
}

void FDance4MeInputDeviceModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}


TSharedPtr<class IInputDevice> FDance4MeInputDeviceModule::CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler)
{
	return TSharedPtr<class IInputDevice>(new MyInputDevice(InMessageHandler));
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDance4MeInputDeviceModule, Dance4MeInputDevice)