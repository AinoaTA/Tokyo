// Fill out your copyright notice in the Description page of Project Settings.


#include "c_Interactable.h"

// Sets default values
Ac_Interactable::Ac_Interactable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Ac_Interactable::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Ac_Interactable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

