// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/WebSocket.h"
#include "Public/WebSocketBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebSocketBase() {}
// Cross Module References
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketRecieve__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_WebSocket();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnected__DelegateSignature();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketClosed__DelegateSignature();
	WEBSOCKET_API UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnectError__DelegateSignature();
	WEBSOCKET_API UClass* Z_Construct_UClass_UWebSocketBase_NoRegister();
	WEBSOCKET_API UClass* Z_Construct_UClass_UWebSocketBase();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBase_Close();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBase_SendText();
// End Cross Module References
	UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketRecieve__DelegateSignature()
	{
		struct _Script_WebSocket_eventWebSocketRecieve_Parms
		{
			FString data;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_data = { UE4CodeGen_Private::EPropertyClass::Str, "data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_WebSocket_eventWebSocketRecieve_Parms, data), METADATA_PARAMS(NewProp_data_MetaData, ARRAY_COUNT(NewProp_data_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_data,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WebSocket, "WebSocketRecieve__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_WebSocket_eventWebSocketRecieve_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnected__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WebSocket, "WebSocketConnected__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketClosed__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WebSocket, "WebSocketClosed__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UDelegateFunction_WebSocket_WebSocketConnectError__DelegateSignature()
	{
		struct _Script_WebSocket_eventWebSocketConnectError_Parms
		{
			FString error;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_error_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_error = { UE4CodeGen_Private::EPropertyClass::Str, "error", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(_Script_WebSocket_eventWebSocketConnectError_Parms, error), METADATA_PARAMS(NewProp_error_MetaData, ARRAY_COUNT(NewProp_error_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_error,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_WebSocket, "WebSocketConnectError__DelegateSignature", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00130000, sizeof(_Script_WebSocket_eventWebSocketConnectError_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	void UWebSocketBase::StaticRegisterNativesUWebSocketBase()
	{
		UClass* Class = UWebSocketBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Close", &UWebSocketBase::execClose },
			{ "SendText", &UWebSocketBase::execSendText },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UWebSocketBase_Close()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBase, "Close", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebSocketBase_SendText()
	{
		struct WebSocketBase_eventSendText_Parms
		{
			FString data;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_data = { UE4CodeGen_Private::EPropertyClass::Str, "data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBase_eventSendText_Parms, data), METADATA_PARAMS(NewProp_data_MetaData, ARRAY_COUNT(NewProp_data_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_data,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBase, "SendText", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(WebSocketBase_eventSendText_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWebSocketBase_NoRegister()
	{
		return UWebSocketBase::StaticClass();
	}
	UClass* Z_Construct_UClass_UWebSocketBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_WebSocket,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UWebSocketBase_Close, "Close" }, // 1211803770
				{ &Z_Construct_UFunction_UWebSocketBase_SendText, "SendText" }, // 2224044882
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "WebSocketBase.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnReceiveData_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnReceiveData = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnReceiveData", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UWebSocketBase, OnReceiveData), Z_Construct_UDelegateFunction_WebSocket_WebSocketRecieve__DelegateSignature, METADATA_PARAMS(NewProp_OnReceiveData_MetaData, ARRAY_COUNT(NewProp_OnReceiveData_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConnectComplete_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectComplete = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConnectComplete", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UWebSocketBase, OnConnectComplete), Z_Construct_UDelegateFunction_WebSocket_WebSocketConnected__DelegateSignature, METADATA_PARAMS(NewProp_OnConnectComplete_MetaData, ARRAY_COUNT(NewProp_OnConnectComplete_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnClosed_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnClosed = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnClosed", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UWebSocketBase, OnClosed), Z_Construct_UDelegateFunction_WebSocket_WebSocketClosed__DelegateSignature, METADATA_PARAMS(NewProp_OnClosed_MetaData, ARRAY_COUNT(NewProp_OnClosed_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OnConnectError_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBase.h" },
			};
#endif
			static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_OnConnectError = { UE4CodeGen_Private::EPropertyClass::MulticastDelegate, "OnConnectError", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000010080000, 1, nullptr, STRUCT_OFFSET(UWebSocketBase, OnConnectError), Z_Construct_UDelegateFunction_WebSocket_WebSocketConnectError__DelegateSignature, METADATA_PARAMS(NewProp_OnConnectError_MetaData, ARRAY_COUNT(NewProp_OnConnectError_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnReceiveData,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConnectComplete,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnClosed,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_OnConnectError,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UWebSocketBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UWebSocketBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebSocketBase, 2987088479);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWebSocketBase(Z_Construct_UClass_UWebSocketBase, &UWebSocketBase::StaticClass, TEXT("/Script/WebSocket"), TEXT("UWebSocketBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWebSocketBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
