// Fill out your copyright notice in the Description page of Project Settings.

#include "MyWorldSettings.h"
#include "CoinCollector.h"

#include "AssetRegistryModule.h"


AMyWorldSettings::AMyWorldSettings()
{
	V_LOG(LogMyGame, Verbose, TEXT("START"));

	const FName PlayerBlueprintObjectPath = FName(TEXT("/Game/CoinCollector/Blueprints/BP_Player.BP_Player"));
	
	AMyWorldSettings::InitDefaultGameMode(PlayerBlueprintObjectPath);
	
	V_LOG(LogMyGame, Verbose, TEXT("END"));
};

void AMyWorldSettings::InitDefaultGameMode(const FName ObjectPath)
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

	DefaultGameMode = PlayerBlueprintObject.GetClass();
	const FString Msg = FString::Printf(
		TEXT("Set \"DefaultGameMode\":  \"%s\""),
		ToCStr(DefaultGameMode->GetName())
	);
	V_LOG(LogMyGame, Verbose, Msg);
}