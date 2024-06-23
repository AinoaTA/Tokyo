#pragma once

#include "CoreMinimal.h" 
#include "GameFramework/Actor.h"  
#include "c_InteractableManager.h"

//esto siempre debajo
#include "InteractableInput.generated.h"  

UCLASS()
class CLASS_API AInteractableInput : public AActor
{
	GENERATED_BODY()

public:
	AInteractableInput();

	void Initialize(Ac_InteractableManager* manager);

private:
	//Ac_InteractableManager* InteractableManager; 

protected:

	virtual void BeginPlay() override;

public:

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "References")
	Ac_InteractableManager* InteractableManager;

	UFUNCTION(BlueprintCallable)
	void SetupInputComponent();

	UFUNCTION(BlueprintCallable)
	void RemoveInteractableFromManager(AInteractableInput* selfInterctable);

#pragma region Events

	//to use when begin play is called. (called in blueprint graph!)
	UFUNCTION(BlueprintImplementableEvent)
	void NextBeginPlay();

	//UFUNCTION(BlueprintCallable, Category = "Interaction")
	UFUNCTION(BlueprintImplementableEvent)
	void Interact();

#pragma endregion 
};
