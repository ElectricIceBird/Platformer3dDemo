// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Pawn.h"
#include "DamageBox.generated.h"

UCLASS()
class PLATFORMER3DDEMO_API ADamageBox : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ADamageBox();
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	USceneComponent* Root;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	UBoxComponent * Box;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float damg;
	UFUNCTION()
	void OnEnter(UPrimitiveComponent*OverlapComponent,
		AActor*OtherActor,UPrimitiveComponent *OtherComponent,
		int32 OtherBodyIndex,bool bFromSweep,const FHitResult &Sweep);
		
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
