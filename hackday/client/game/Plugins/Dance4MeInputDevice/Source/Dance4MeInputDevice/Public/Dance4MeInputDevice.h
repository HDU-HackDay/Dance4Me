// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ModuleManager.h"
#include "WebSocketBase.h"
#include <../InputDevice/Public/IInputDeviceModule.h>

class FDance4MeInputDeviceModule : public IInputDeviceModule
{
public:
	UPROPERTY()
	UWebSocketBase* WebsocketBaseInstance;
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	virtual TSharedPtr<class IInputDevice> CreateInputDevice(const TSharedRef<FGenericApplicationMessageHandler>& InMessageHandler) override;

};