// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()

{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup "Camera Rig"
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	// Set default Transformation for "Camera Rig"
	const float InitPitchValue = -50.0f;
	const float InitYawValue = 0.0f;
	const float InitRollValue = 0.0f;
	
	FRotator NewRotation = FRotator(InitPitchValue, InitYawValue, InitRollValue);
	SpringArm->SetRelativeRotation(NewRotation, false, 0, ETeleportType::None);

	const float InitTargetArmLength = 1000.0f;
	SpringArm->TargetArmLength = InitTargetArmLength;
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
}
