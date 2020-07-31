// Fill out your copyright notice in the Description page of Project Settings.

#include "MyWorldSettings.h"
#include "CoinCollector.h"

#include "AssetRegistryModule.h"
#include "LevelEditorActions.h"


AMyWorldSettings::AMyWorldSettings()
{
	V_LOG(LogMyGame, Verbose, TEXT("START"));

	const FName DefaultGameModePath = FName(TEXT("/Game/CoinCollector/Blueprints/GM_Tutorial.GM_Tutorial'"));
	
	//AMyWorldSettings::InitDefaultGameMode(DefaultGameModePath);
	
	V_LOG(LogMyGame, Verbose, TEXT("END"));
};

void AMyWorldSettings::InitDefaultGameMode(const FName ObjectPath)
{

	UBlueprint* PlayerMesh = ConstructorHelpers::FObjectFinder<UBlueprint>
		(*ObjectPath.ToString()).Object;

	LevelEditor
	
	//// Validate that the path to the object exists
	//FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	//const FAssetData DefaultGameModeObject = AssetRegistryModule.Get()
	//	.GetAssetByObjectPath(ObjectPath, true);

	////if (!DefaultGameModeObject.IsValid())
	////{
	////	const FString Msg = FString::Printf(
	////		TEXT("Unable to find default player asset path: \"%s\""),
	////		ToCStr(ObjectPath.ToString())
	////	);
	////	V_LOG(LogMyGame, Warning, Msg);
	////	return;
	////}

	////// Setup defaults...

	//if (DefaultGameModeObject.IsValid())
	//{
		////DefaultGameMode = PlayerMesh;
		//const FString Msg = FString::Printf(
		//	TEXT("Set \"DefaultGameMode\":  \"%s\""),
		//	ToCStr(DefaultGameMode->GetName())
		//);
	//}
	//
	//V_LOG(LogMyGame, Verbose, Msg);
}