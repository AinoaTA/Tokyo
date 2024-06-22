// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"  

//esto siempre debajo
#include "InteractableInput.generated.h"  
  
UCLASS()
class CLASS_API AInteractableInput : public AActor
{
	GENERATED_BODY()

public: 
	AInteractableInput();
	//void Initialize(Ac_InteractableManager* manager);

private:
	 //Ac_InteractableManager* InteractableManager; 

protected: 

	virtual void BeginPlay() override;

public:  

	virtual void Tick(float DeltaTime) override;
	 
	void SetupInputComponent(); 



	//UFUNCTION(BlueprintCallable, Category = "Interaction")
	UFUNCTION(BlueprintImplementableEvent)
	void Interact(); 
};
