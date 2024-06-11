// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableInput.h"

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

// Called every frame
void AInteractableInput::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

