// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword_Base.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ASword_Base::ASword_Base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	

}



// Called when the game starts or when spawned
void ASword_Base::BeginPlay()
{
	Super::BeginPlay();
	if(TheOwner)
	{
		UE_LOG(LogTemp,Warning,TEXT(" Is Owner"));
	}
}

// Called every frame
void ASword_Base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

 void ASword_Base::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(OtherActor->ActorHasTag("Enemy"))
	{
		UE_LOG(LogTemp,Warning,TEXT(" Is Owner"));
	}
}