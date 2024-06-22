#include "InteractableInput.h"  
#include "GameFramework/PlayerController.h" 
#include <Kismet/GameplayStatics.h>
#include "Components/InputComponent.h" 


AInteractableInput::AInteractableInput()
{
	PrimaryActorTick.bCanEverTick = true;
	 

	UE_LOG(LogTemp, Warning, TEXT("Loading Constructor..."));
}

//void AInteractableInput::Initialize(Ac_InteractableManager* manager)
//{
//	InteractableManager = manager;
//}

void AInteractableInput::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Interaction Begin play"));
	Super::BeginPlay();

	SetupInputComponent();

}

void AInteractableInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInteractableInput::SetupInputComponent()
{
	APlayerController* FirstLocalPlayer = UGameplayStatics::GetPlayerController(this, 0);

	// Ensure that the PlayerController and its InputComponent are valid before binding
	if (IsValid(FirstLocalPlayer) && IsValid(FirstLocalPlayer->InputComponent))
	{
		// Use BindAction or BindAxis on the InputComponent to establish the bindings
		FirstLocalPlayer->InputComponent->BindAction(FName("c_interaction"), IE_Pressed, this, &AInteractableInput::Interact);
	}

	/*UE_LOG(LogTemp, Warning, TEXT("Setup Input!!! "));

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();

	if (PlayerController)
	{
		InputComponent = NewObject<UInputComponent>(this);
		InputComponent->RegisterComponent();

		InputComponent->BindAction("c_interaction", IE_Pressed, this, &AInteractableInput::Interact);
		PlayerController->PushInputComponent(InputComponent);
	}*/




	//InputComponent = NewObject<UInputComponent>(this);
	//if (InputComponent)
	//{
	//	InputComponent->RegisterComponent();
	//	InputComponent->BindAction("c_interaction", IE_Pressed, this, &AInteractableInput::Interact);

	//	UE_LOG(LogTemp, Warning, TEXT("setted"));
	//}
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
