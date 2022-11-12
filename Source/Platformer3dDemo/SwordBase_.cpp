// Fill out your copyright notice in the Description page of Project Settings.


#include "SwordBase_.h"

// Sets default values
ASwordBase_::ASwordBase_()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASwordBase_::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwordBase_::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(theOwner)
	{
		UE_LOG(LogTemp,Warning,TEXT(" Is Owner"));
	}
}

// Called to bind functionality to input
void ASwordBase_::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ASwordBase_::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if(OtherActor == theOwner)
	{
		SetActorEnableCollision(false);
	}
}