// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/WebSocket.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebSocket_init() {}
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnectError__DelegateSignature();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketClosed__DelegateSignature();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnected__DelegateSignature();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketRecieve__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_WebSocket()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_WebSocket_WebSocketConnectError__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebSocket_WebSocketClosed__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebSocket_WebSocketConnected__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_WebSocket_WebSocketRecieve__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/WebSocket",
				PKG_CompiledIn | 0x00000000,
				0x337A0C29,
				0x0D1B63B0,
				SingletonFuncArray, ARRAY_COUNT(SingletonFuncArray),
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
