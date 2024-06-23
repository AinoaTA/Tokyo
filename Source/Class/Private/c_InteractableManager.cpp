// Fill out your copyright notice in the Description page of Project Settings.


#include "c_InteractableManager.h"

#include "InteractableInput.h"  
#include <Kismet/GameplayStatics.h>  


// Sets default values
Ac_InteractableManager::Ac_InteractableManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ac_InteractableManager::BeginPlay()
{
	Super::BeginPlay();


	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AInteractableInput::StaticClass(), FoundActors);

	for (size_t i = 0; i < FoundActors.Num(); i++)
	{
		AddInteractable(Cast<AInteractableInput>(FoundActors[i]));
		//_interactables.Last()->OnInteraction.BindUFunction(this, FName("RemoveInteractable"));
		_interactables.Last()->Initialize(this);
	}
}

// Called every frame
void Ac_InteractableManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void Ac_InteractableManager::AddInteractable(AInteractableInput* Interactable)
{
	_interactables.Add(Interactable);
}

void Ac_InteractableManager::RemoveInteractable(AInteractableInput* Interactable)
{
	UE_LOG(LogTemp, Warning, TEXT("removinf.. lol"));
	_interactables.Remove(Interactable);
}

