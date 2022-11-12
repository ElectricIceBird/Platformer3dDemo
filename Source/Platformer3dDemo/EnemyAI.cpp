// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAI.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
// Sets default values
AEnemyAI::AEnemyAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(Health<=0)
	{
		if(Death)
		{

			PlayAnimMontage(Death,3,NAME_None);
		}
	}

}

// Called to bind functionality to input
void AEnemyAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void AEnemyAI::OnBeginOverlap(class UPrimitiveComponent*HitComp,
                              const class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult )
		{
	
		if(OtherActor->ActorHasTag("Sword"))
		{
			UE_LOG(LogTemp,Warning,TEXT("WorkignCollison"));
		
			Health-=10;
			

		}
	}
	

