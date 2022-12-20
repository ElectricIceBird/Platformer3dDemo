// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIBOT_CHARACTER.generated.h"

UCLASS()
class PLATFORMER3DDEMO_API AAIBOT_CHARACTER : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIBOT_CHARACTER();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	class AWaypoint* NextWayPoint;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	float health;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Animations)
	UAnimMontage *DeathAnim;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Animations)
	UAnimMontage *HurtAnim;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = Animations)
	UAnimMontage *AttackAnim;
	UFUNCTION()
	void Damage(float attack);
	UFUNCTION()
	void Delay();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
