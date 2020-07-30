// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "MyGameMode.generated.h"

/**
 * 
 */
UCLASS()
class COINCOLLECTOR_API AMyGameMode : public AGameModeBase
{
	GENERATED_BODY()

	AMyGameMode();

protected:
	void InitDefaultPawnClass(const FName ObjectPath);
};
