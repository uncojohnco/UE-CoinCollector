// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"
#include "CoinCollector.h"

#include "AssetRegistryModule.h"


// Sets default values
ABasePlayer::ABasePlayer()

{
	V_LOG(LogMyGame, Verbose, TEXT("START"));
	
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Setup "Camera Rig"
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	
	RootComponent = Mesh;
	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

	// Set Defaults for "Camera Rig"
	// TODO: Change these to be data driven
	
	SpringArmRotation = FRotator(-100.0f, 0, 0);
	SpringArmTargetLength = 1000.0f;

	SpringArm->SetWorldRotation(SpringArmRotation, false, nullptr, ETeleportType::None);
	SpringArm->TargetArmLength = SpringArmTargetLength;

	// Set Defaults for "Player"
	// TODO: Change these to be data driven

	MovementForce = 90000;
	const FName PlayerMeshObjectPath = FName(TEXT("/Game/CoinCollector/Meshes/SM_Sphere.SM_Sphere"));

    ABasePlayer::InitPlayerMesh(PlayerMeshObjectPath);
	
	V_LOG(LogMyGame, Verbose, TEXT("END"));
}

// Setup the Player mesh from defaults
void ABasePlayer::InitPlayerMesh(const FName ObjectPath)
{
	// Validate that the path to the object exists
	FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>("AssetRegistry");
	const FAssetData PlayerMeshObject = AssetRegistryModule.Get()
		.GetAssetByObjectPath(ObjectPath, true);

	if (!PlayerMeshObject.IsValid())
	{
		const FString Msg = FString::Printf(TEXT("Unable to find \"PlayerMeshObjectPath\" path: \"%s\""), *ObjectPath.ToString());
		V_LOG(LogMyGame, Warning, Msg);
		return;
	}

	PlayerMesh = ConstructorHelpers::FObjectFinder<UStaticMesh>
		(*ObjectPath.ToString()).Object;
	Mesh->SetStaticMesh(PlayerMesh);
	Mesh->SetSimulatePhysics(true);
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
	
	InputComponent->BindAxis("MoveUp", this, &ABasePlayer::MoveUp);
	InputComponent->BindAxis("MoveRight", this, &ABasePlayer::MoveRight);
}

#if WITH_EDITOR
void ABasePlayer::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	UProperty* PropertyThatChanged = PropertyChangedEvent.Property;
	
	if (PropertyThatChanged == nullptr)
	{
		return;
	}

	const FString PropertyName = PropertyThatChanged->GetName();

	if (PropertyName == TEXT("SpringArmRotation"))
	{
		SpringArm->SetWorldRotation(SpringArmRotation, false, 0, ETeleportType::None);
	}
	else if (PropertyName == TEXT("SpringArmTargetLength"))
	{
		SpringArm->TargetArmLength = SpringArmTargetLength;
	}
	else if (PropertyName == TEXT("PlayerMesh"))
	{
		Mesh->SetStaticMesh(PlayerMesh);
		Mesh->SetSimulatePhysics(true);
	}

}
#endif

// Player Movement Behaviour
void ABasePlayer::MoveUp(float Value)
{
	FVector ForceToAdd = FVector(1, 0, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}

void ABasePlayer::MoveRight(float Value)
{
	FVector ForceToAdd = FVector(0, 1, 0) * MovementForce * Value;
	Mesh->AddForce(ForceToAdd);
}
