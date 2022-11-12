// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h "
#include "GameFramework/CharacterMovementComponent.h "
#include "GameFramework/Controller.h "
#include  "GameFramework/SpringArmComponent.h "
#include "Blueprint/UserWidget.h "



#include "ZU.generated.h"

UCLASS()
class PLATFORMER3DDEMO_API AZU : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AZU();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Camera)
		USpringArmComponent * CameraBoom;
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category = Camera)
		UCameraComponent * FollowCamera;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Animations)
		UAnimMontage *AttackAnim;	

	     
	
	
	void MoveForward(float axis);
	void MoveRight(float axis);
	void Attack();
	bool bDead;	

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
		float power;
	UPROPERTY(EditAnywhere)
		float Power_Treshold;	
	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent*HitComp,
			class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult );	
	UPROPERTY(EditAnywhere,Category= "UI HUD")
		TSubclassOf<UUserWidget> Player_Power_Widget_Class;
	UUserWidget* Player_Power_Widget;	

void RestartGame();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	// UPROPERTY(EditAnywhere,meta = (AllowPrivateAccess = "true"));
	// TSubclassOf<AActor> Sword;
	// // Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
