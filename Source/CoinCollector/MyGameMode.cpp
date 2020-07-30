// Fill out your copyright notice in the Description page of Project Settings.

#include "MyGameMode.h"
#include "CoinCollector.h"

#include "AssetRegistryModule.h"


AMyGameMode::AMyGameMode()
{
	V_LOG(LogMyGame, Verbose, TEXT("START"));
	
	const FName PlayerBlueprintObjectPath = FName(TEXT("/Game/CoinCollector/Blueprints/BP_Player.BP_Player"));

	AMyGameMode::InitDefaultPawnClass(PlayerBlueprintObjectPath);
	
	V_LOG(LogMyGame, Verbose, TEXT("END"));
}


void AMyGameMode::InitDefaultPawnClass(const FName ObjectPath)
{
	// Validate that the path to the object exists
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	const FAssetData PlayerBlueprintObject = AssetRegistryModule.Get()
		.GetAssetByObjectPath(ObjectPath, true);

	if (!PlayerBlueprintObject.IsValid())
	{
		const FString Msg = FString::Printf(
			TEXT("Unable to find default player asset path: \"%s\""),
			ToCStr(ObjectPath.ToString())
		);
		V_LOG(LogMyGame, Warning, Msg);
		return;
	}

	// Setup defaults...

	DefaultPawnClass = PlayerBlueprintObject.GetClass();
	const FString Msg = FString::Printf(
		TEXT("Set \"DefautPawnClass\":  \"%s\""),
		ToCStr(DefaultPawnClass->GetName())
	);
	V_LOG(LogMyGame, Verbose, Msg);
}