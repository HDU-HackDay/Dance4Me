// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Public/WebSocket.h"
#include "Public/WebSocketBlueprintLibrary.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWebSocketBlueprintLibrary() {}
// Cross Module References
	WEBSOCKET_API UScriptStruct* Z_Construct_UScriptStruct_FWebSocketHeaderPair();
	UPackage* Z_Construct_UPackage__Script_WebSocket();
	WEBSOCKET_API UClass* Z_Construct_UClass_UTest_NoRegister();
	WEBSOCKET_API UClass* Z_Construct_UClass_UTest();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject();
	WEBSOCKET_API UClass* Z_Construct_UClass_UTest2_NoRegister();
	WEBSOCKET_API UClass* Z_Construct_UClass_UTest2();
	WEBSOCKET_API UClass* Z_Construct_UClass_UWebSocketBlueprintLibrary_NoRegister();
	WEBSOCKET_API UClass* Z_Construct_UClass_UWebSocketBlueprintLibrary();
	ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_Connect();
	WEBSOCKET_API UClass* Z_Construct_UClass_UWebSocketBase_NoRegister();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_ConnectWithHeader();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_GetJsonIntField();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_JsonToObject();
	COREUOBJECT_API UClass* Z_Construct_UClass_UObject_NoRegister();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	WEBSOCKET_API UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_ObjectToJson();
// End Cross Module References
class UScriptStruct* FWebSocketHeaderPair::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern WEBSOCKET_API uint32 Get_Z_Construct_UScriptStruct_FWebSocketHeaderPair_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FWebSocketHeaderPair, Z_Construct_UPackage__Script_WebSocket(), TEXT("WebSocketHeaderPair"), sizeof(FWebSocketHeaderPair), Get_Z_Construct_UScriptStruct_FWebSocketHeaderPair_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FWebSocketHeaderPair(FWebSocketHeaderPair::StaticStruct, TEXT("/Script/WebSocket"), TEXT("WebSocketHeaderPair"), false, nullptr, nullptr);
static struct FScriptStruct_WebSocket_StaticRegisterNativesFWebSocketHeaderPair
{
	FScriptStruct_WebSocket_StaticRegisterNativesFWebSocketHeaderPair()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("WebSocketHeaderPair")),new UScriptStruct::TCppStructOps<FWebSocketHeaderPair>);
	}
} ScriptStruct_WebSocket_StaticRegisterNativesFWebSocketHeaderPair;
	UScriptStruct* Z_Construct_UScriptStruct_FWebSocketHeaderPair()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FWebSocketHeaderPair_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_WebSocket();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("WebSocketHeaderPair"), sizeof(FWebSocketHeaderPair), Get_Z_Construct_UScriptStruct_FWebSocketHeaderPair_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			auto NewStructOpsLambda = []() -> void* { return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWebSocketHeaderPair>(); };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_value = { UE4CodeGen_Private::EPropertyClass::Str, "value", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FWebSocketHeaderPair, value), METADATA_PARAMS(NewProp_value_MetaData, ARRAY_COUNT(NewProp_value_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_key_MetaData[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_key = { UE4CodeGen_Private::EPropertyClass::Str, "key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(FWebSocketHeaderPair, key), METADATA_PARAMS(NewProp_key_MetaData, ARRAY_COUNT(NewProp_key_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_value,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_key,
			};
			static const UE4CodeGen_Private::FStructParams ReturnStructParams = {
				(UObject* (*)())Z_Construct_UPackage__Script_WebSocket,
				nullptr,
				&UE4CodeGen_Private::TNewCppStructOpsWrapper<decltype(NewStructOpsLambda)>::NewCppStructOps,
				"WebSocketHeaderPair",
				RF_Public|RF_Transient|RF_MarkAsNative,
				EStructFlags(0x00000001),
				sizeof(FWebSocketHeaderPair),
				alignof(FWebSocketHeaderPair),
				PropPointers, ARRAY_COUNT(PropPointers),
				METADATA_PARAMS(Struct_MetaDataParams, ARRAY_COUNT(Struct_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FWebSocketHeaderPair_CRC() { return 3682112262U; }
	void UTest::StaticRegisterNativesUTest()
	{
	}
	UClass* Z_Construct_UClass_UTest_NoRegister()
	{
		return UTest::StaticClass();
	}
	UClass* Z_Construct_UClass_UTest()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_WebSocket,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "WebSocketBlueprintLibrary.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mAge_MetaData[] = {
				{ "Category", "Test" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_mAge = { UE4CodeGen_Private::EPropertyClass::Int, "mAge", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UTest, mAge), METADATA_PARAMS(NewProp_mAge_MetaData, ARRAY_COUNT(NewProp_mAge_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mName_MetaData[] = {
				{ "Category", "Test" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_mName = { UE4CodeGen_Private::EPropertyClass::Str, "mName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UTest, mName), METADATA_PARAMS(NewProp_mName_MetaData, ARRAY_COUNT(NewProp_mName_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mAge,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mName,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UTest>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UTest::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00000080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(UTest, 2897851810);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTest(Z_Construct_UClass_UTest, &UTest::StaticClass, TEXT("/Script/WebSocket"), TEXT("UTest"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTest);
	void UTest2::StaticRegisterNativesUTest2()
	{
	}
	UClass* Z_Construct_UClass_UTest2_NoRegister()
	{
		return UTest2::StaticClass();
	}
	UClass* Z_Construct_UClass_UTest2()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UObject,
				(UObject* (*)())Z_Construct_UPackage__Script_WebSocket,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "IncludePath", "WebSocketBlueprintLibrary.h" },
				{ "IsBlueprintBase", "true" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mTest_MetaData[] = {
				{ "Category", "Test" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_mTest = { UE4CodeGen_Private::EPropertyClass::Object, "mTest", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UTest2, mTest), Z_Construct_UClass_UTest_NoRegister, METADATA_PARAMS(NewProp_mTest_MetaData, ARRAY_COUNT(NewProp_mTest_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mAge_MetaData[] = {
				{ "Category", "Test" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_mAge = { UE4CodeGen_Private::EPropertyClass::Int, "mAge", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UTest2, mAge), METADATA_PARAMS(NewProp_mAge_MetaData, ARRAY_COUNT(NewProp_mAge_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_mName_MetaData[] = {
				{ "Category", "Test" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_mName = { UE4CodeGen_Private::EPropertyClass::Str, "mName", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000005, 1, nullptr, STRUCT_OFFSET(UTest2, mName), METADATA_PARAMS(NewProp_mName_MetaData, ARRAY_COUNT(NewProp_mName_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mTest,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mAge,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_mName,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UTest2>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UTest2::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00000080u,
				nullptr, 0,
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
	IMPLEMENT_CLASS(UTest2, 894048104);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UTest2(Z_Construct_UClass_UTest2, &UTest2::StaticClass, TEXT("/Script/WebSocket"), TEXT("UTest2"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UTest2);
	void UWebSocketBlueprintLibrary::StaticRegisterNativesUWebSocketBlueprintLibrary()
	{
		UClass* Class = UWebSocketBlueprintLibrary::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Connect", &UWebSocketBlueprintLibrary::execConnect },
			{ "ConnectWithHeader", &UWebSocketBlueprintLibrary::execConnectWithHeader },
			{ "GetJsonIntField", &UWebSocketBlueprintLibrary::execGetJsonIntField },
			{ "JsonToObject", &UWebSocketBlueprintLibrary::execJsonToObject },
			{ "ObjectToJson", &UWebSocketBlueprintLibrary::execObjectToJson },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_Connect()
	{
		struct WebSocketBlueprintLibrary_eventConnect_Parms
		{
			FString url;
			UWebSocketBase* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventConnect_Parms, ReturnValue), Z_Construct_UClass_UWebSocketBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_url_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_url = { UE4CodeGen_Private::EPropertyClass::Str, "url", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventConnect_Parms, url), METADATA_PARAMS(NewProp_url_MetaData, ARRAY_COUNT(NewProp_url_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_url,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBlueprintLibrary, "Connect", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WebSocketBlueprintLibrary_eventConnect_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_ConnectWithHeader()
	{
		struct WebSocketBlueprintLibrary_eventConnectWithHeader_Parms
		{
			FString url;
			TArray<FWebSocketHeaderPair> header;
			UWebSocketBase* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventConnectWithHeader_Parms, ReturnValue), Z_Construct_UClass_UWebSocketBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_header_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FArrayPropertyParams NewProp_header = { UE4CodeGen_Private::EPropertyClass::Array, "header", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000008000182, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventConnectWithHeader_Parms, header), METADATA_PARAMS(NewProp_header_MetaData, ARRAY_COUNT(NewProp_header_MetaData)) };
			static const UE4CodeGen_Private::FStructPropertyParams NewProp_header_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "header", RF_Public|RF_Transient|RF_MarkAsNative, 0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FWebSocketHeaderPair, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_url_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_url = { UE4CodeGen_Private::EPropertyClass::Str, "url", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventConnectWithHeader_Parms, url), METADATA_PARAMS(NewProp_url_MetaData, ARRAY_COUNT(NewProp_url_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_header,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_header_Inner,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_url,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBlueprintLibrary, "ConnectWithHeader", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(WebSocketBlueprintLibrary_eventConnectWithHeader_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_GetJsonIntField()
	{
		struct WebSocketBlueprintLibrary_eventGetJsonIntField_Parms
		{
			FString data;
			FString key;
			int32 iValue;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((WebSocketBlueprintLibrary_eventGetJsonIntField_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WebSocketBlueprintLibrary_eventGetJsonIntField_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_iValue = { UE4CodeGen_Private::EPropertyClass::Int, "iValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventGetJsonIntField_Parms, iValue), METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_key_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_key = { UE4CodeGen_Private::EPropertyClass::Str, "key", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventGetJsonIntField_Parms, key), METADATA_PARAMS(NewProp_key_MetaData, ARRAY_COUNT(NewProp_key_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_data = { UE4CodeGen_Private::EPropertyClass::Str, "data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventGetJsonIntField_Parms, data), METADATA_PARAMS(NewProp_data_MetaData, ARRAY_COUNT(NewProp_data_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_iValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_key,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_data,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBlueprintLibrary, "GetJsonIntField", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(WebSocketBlueprintLibrary_eventGetJsonIntField_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_JsonToObject()
	{
		struct WebSocketBlueprintLibrary_eventJsonToObject_Parms
		{
			FString data;
			UClass* StructDefinition;
			bool checkAll;
			UObject* ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventJsonToObject_Parms, ReturnValue), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			auto NewProp_checkAll_SetBit = [](void* Obj){ ((WebSocketBlueprintLibrary_eventJsonToObject_Parms*)Obj)->checkAll = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_checkAll = { UE4CodeGen_Private::EPropertyClass::Bool, "checkAll", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WebSocketBlueprintLibrary_eventJsonToObject_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_checkAll_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FClassPropertyParams NewProp_StructDefinition = { UE4CodeGen_Private::EPropertyClass::Class, "StructDefinition", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventJsonToObject_Parms, StructDefinition), Z_Construct_UClass_UObject_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_data_MetaData[] = {
				{ "NativeConst", "" },
			};
#endif
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_data = { UE4CodeGen_Private::EPropertyClass::Str, "data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventJsonToObject_Parms, data), METADATA_PARAMS(NewProp_data_MetaData, ARRAY_COUNT(NewProp_data_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_checkAll,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_StructDefinition,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_data,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBlueprintLibrary, "JsonToObject", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04022401, sizeof(WebSocketBlueprintLibrary_eventJsonToObject_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UWebSocketBlueprintLibrary_ObjectToJson()
	{
		struct WebSocketBlueprintLibrary_eventObjectToJson_Parms
		{
			UObject* Object;
			FString data;
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((WebSocketBlueprintLibrary_eventObjectToJson_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(WebSocketBlueprintLibrary_eventObjectToJson_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FStrPropertyParams NewProp_data = { UE4CodeGen_Private::EPropertyClass::Str, "data", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000180, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventObjectToJson_Parms, data), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Object = { UE4CodeGen_Private::EPropertyClass::Object, "Object", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(WebSocketBlueprintLibrary_eventObjectToJson_Parms, Object), Z_Construct_UClass_UObject_NoRegister, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_data,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Object,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "WebSocket" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UWebSocketBlueprintLibrary, "ObjectToJson", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04422401, sizeof(WebSocketBlueprintLibrary_eventObjectToJson_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UWebSocketBlueprintLibrary_NoRegister()
	{
		return UWebSocketBlueprintLibrary::StaticClass();
	}
	UClass* Z_Construct_UClass_UWebSocketBlueprintLibrary()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
				(UObject* (*)())Z_Construct_UPackage__Script_WebSocket,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UWebSocketBlueprintLibrary_Connect, "Connect" }, // 322240689
				{ &Z_Construct_UFunction_UWebSocketBlueprintLibrary_ConnectWithHeader, "ConnectWithHeader" }, // 1114602316
				{ &Z_Construct_UFunction_UWebSocketBlueprintLibrary_GetJsonIntField, "GetJsonIntField" }, // 1306093830
				{ &Z_Construct_UFunction_UWebSocketBlueprintLibrary_JsonToObject, "JsonToObject" }, // 4244975175
				{ &Z_Construct_UFunction_UWebSocketBlueprintLibrary_ObjectToJson, "ObjectToJson" }, // 2401553097
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "WebSocketBlueprintLibrary.h" },
				{ "ModuleRelativePath", "Public/WebSocketBlueprintLibrary.h" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UWebSocketBlueprintLibrary>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UWebSocketBlueprintLibrary::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00100080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UWebSocketBlueprintLibrary, 1400233510);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UWebSocketBlueprintLibrary(Z_Construct_UClass_UWebSocketBlueprintLibrary, &UWebSocketBlueprintLibrary::StaticClass, TEXT("/Script/WebSocket"), TEXT("UWebSocketBlueprintLibrary"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UWebSocketBlueprintLibrary);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
