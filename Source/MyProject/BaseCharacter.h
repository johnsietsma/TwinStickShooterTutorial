// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS(Blueprintable)
class MYPROJECT_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "BaseCharacter")
        float Health = 100;

    UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "BaseCharacter")
        bool isDead = false;

    virtual void CalculateDead();

    UFUNCTION(BlueprintCallable, Category = "BaseCharacter")
        virtual void CalculateHealth(float delta);

#if WITH_EDITOR
    virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent);
#endif

public:
	// Sets default values for this character's properties
	ABaseCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	
	
};
