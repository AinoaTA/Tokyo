// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputAction.h"
#include "EnhancedInput/Public/EnhancedInputComponent.h" 
#include "../../../../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedActionKeyMapping.h"


#include "InteractableInput.generated.h" 

UCLASS()
class CLASS_API AInteractableInput : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AInteractableInput();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputMappingContext* inputMappingContext;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Enhanced Input")
	UInputAction* inputToInteract;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void EnhancedInputInteraction();

	void SetupInputComponent(class UInputComponent* InputComponent);

public:

	void Interaction(); 
	void NotifyActorBeginOverlap(AActor* OtherActor);
	void NotifyActorEndOverlap(AActor* OtherActor);
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
