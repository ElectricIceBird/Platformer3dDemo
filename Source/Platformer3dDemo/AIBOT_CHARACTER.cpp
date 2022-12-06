// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBOT_CHARACTER.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AAIBOT_CHARACTER::AAIBOT_CHARACTER()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate= FRotator(0.0f,600.0f,0.0f);
}

// Called when the game starts or when spawned
void AAIBOT_CHARACTER::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAIBOT_CHARACTER::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIBOT_CHARACTER::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

