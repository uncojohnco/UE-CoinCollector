// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/WorldSettings.h"

#include "MyWorldSettings.generated.h"


/**
 * 
 */
UCLASS(Config = Game)
class COINCOLLECTOR_API AMyWorldSettings : public AWorldSettings
{
	GENERATED_BODY()

public:

	AMyWorldSettings();

protected:

	void InitDefaultGameMode(const FName ObjectPath);
};
