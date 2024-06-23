#include "InteractableInput.h"  
#include "GameFramework/PlayerController.h" 
#include <Kismet/GameplayStatics.h>
#include "Components/InputComponent.h" 


AInteractableInput::AInteractableInput()
{
	PrimaryActorTick.bCanEverTick = true;
	 

	UE_LOG(LogTemp, Warning, TEXT("Loading Constructor..."));
}

void AInteractableInput::Initialize(Ac_InteractableManager* manager)
{
	InteractableManager = manager;
} 

void AInteractableInput::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Interaction Begin play"));
	Super::BeginPlay();

	NextBeginPlay();

	SetupInputComponent(); 
}

void AInteractableInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableInput::SetupInputComponent()
{
	//UE_LOG(LogTemp, Warning, TEXT("Entering in SetInputComponent"));

	APlayerController* FirstLocalPlayer = UGameplayStatics::GetPlayerController(this, 0);

	// Ensure that the PlayerController and its InputComponent are valid before binding
	if (IsValid(FirstLocalPlayer) && IsValid(FirstLocalPlayer->InputComponent))
	{
		/*UE_LOG(LogTemp, Warning, TEXT("Input Set"));*/
		 
		FirstLocalPlayer->InputComponent->BindAction(FName("c_interaction"), IE_Pressed, this, &AInteractableInput::Interact);
	} 
}

void AInteractableInput::RemoveInteractableFromManager(AInteractableInput* selfInterctable)
{
	InteractableManager->RemoveInteractable(selfInterctable);
}
 

//// Function to handle interaction input
//void AInteractableInput::Interact()
//{
//	UE_LOG(LogTemp, Warning, TEXT("Interaction Event Is calling"));
//	 
//	//InteractableManager->RemoveInteractable(this);
//
//	// Add your interaction logic here
//}
