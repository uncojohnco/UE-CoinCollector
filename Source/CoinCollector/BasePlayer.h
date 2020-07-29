// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

#include "BasePlayer.generated.h"


//General Log
DECLARE_LOG_CATEGORY_EXTERN(LogMyGame, Log, All);


UCLASS(Config = BasePlayer)
class COINCOLLECTOR_API ABasePlayer : public APawn
{
	GENERATED_BODY()
	
public:
	
	// Camera Setup

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UCameraComponent* Camera;

	// TODO: Change below to be data driven
	
	// Rotation Lock of the Camera around the Player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FRotator SpringArmRotation;

	// Target Length of the Camera to be away from the Player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SpringArmTargetLength;

	// Player Movement Behaviour
	
	// Mesh representing the Player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UStaticMesh* PlayerMesh;

	// Force multiplier applied when moving the Player
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float MovementForce;
	
	// Sets default values for this pawn's properties
	ABasePlayer();

protected:
	// Called when the game starts or when spawned
	void BeginPlay() override;
	virtual void InitPlayerMesh(const FName PlayerMeshObjectPath);
	
public:	
	// Called every frame
	void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
	
	void MoveUp(float Value);
	void MoveRight(float Value);
};
