// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableInput.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h" 
#include <Kismet/GameplayStatics.h>

#include "../../../../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/*.h" 

// Sets default values
AInteractableInput::AInteractableInput()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInteractableInput::BeginPlay()
{
	Super::BeginPlay();
	
}

void AInteractableInput::EnhancedInputInteraction()
{
}

void AInteractableInput::SetupInputComponent(UInputComponent* InputComponent)
{
	InputComponent->BindAction("Interaction", IE_Pressed, this, &AInteractableInput::Interaction);

	//UEnhancedInputComponent* enhanched = Cast< UEnhancedInputComponent>(InputComponent);

	//enhanched-> BlindAction(inputToInteract, ETriggerEvent::Triggered, this,  &AInteractableInput::Interaction)

}
void AInteractableInput::BeginPlay()
{
    Super::BeginPlay();

    // Enable input
    APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
    if (PlayerController)
    {
        EnableInput(PlayerController);

        if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerController->InputComponent))
        {
            if (inputToInteract)
            {
                EnhancedInputComponent->BindAction(inputToInteract, ETriggerEvent::Triggered, this, &AInteractableInput::Interaction);
            }
        }

        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
        {
            UInputMappingContext* IMC_Default = LoadObject<UInputMappingContext>(nullptr, TEXT("/Game/Input/IMC_Default.IMC_Default"));
            if (IMC_Default)
            {
                Subsystem->AddMappingContext(IMC_Default, 1);
            }
        }
    }
}

void AInteractableInput::Interaction()
{
	UE_LOG(LogTemp, Warning, TEXT("Interacted with object!"));
}


// Called every frame
void AInteractableInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

