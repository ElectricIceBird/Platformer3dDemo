// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SwordBase_.generated.h"

UCLASS()
class PLATFORMER3DDEMO_API ASwordBase_ : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASwordBase_();
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float swordDamage;

	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	AActor*theOwner = GetOwner();
	
	UFUNCTION()
	void
	BeginOverlap(UPrimitiveComponent*OverlappedComponent,
		AActor*OtherActor,
		UPrimitiveComponent*OtherComp,int32 OtherBodyIndex,bool bFromSweep,const FHitResult &SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
