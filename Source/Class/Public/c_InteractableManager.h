// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <InteractableInput.h>
 
#include "c_InteractableManager.generated.h" 

UCLASS()
class CLASS_API Ac_InteractableManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Ac_InteractableManager();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactables")
    TArray<AInteractableInput*> _interactables;
     
    UFUNCTION(BlueprintCallable, Category = "Interactables")
    void AddInteractable(AInteractableInput* Interactable);
     
    UFUNCTION(BlueprintCallable, Category = "Interactables")
    void RemoveInteractable(AInteractableInput* Interactable); 
};
