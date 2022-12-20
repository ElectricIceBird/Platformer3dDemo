// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBOT_CHARACTER.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyAIController.h"
// Sets default values
AAIBOT_CHARACTER::AAIBOT_CHARACTER()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate= FRotator(0.0f,600.0f,0.0f);
}

void AAIBOT_CHARACTER::Damage(float attack)
{
	if(HurtAnim)
	{
		PlayAnimMontage(HurtAnim,1,NAME_None);
		health-=attack;
	}
}

void AAIBOT_CHARACTER::Delay()
{
	UE_LOG(LogTemp,Warning,TEXT("OW"));

	FTimerHandle TDelay;
	GetWorld()->GetTimerManager().SetTimer(TDelay,this,&AAIBOT_CHARACTER::Delay,100.0f,false);
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
	if(health<=0)
	{
		if(DeathAnim)
		{
			PlayAnimMontage(DeathAnim,1,NAME_None);
			
		}
		UE_LOG(LogTemp,Warning,TEXT("DEATH!!!"));
		Delay();

		Destroy();
	}
	
}

// Called to bind functionality to input
void AAIBOT_CHARACTER::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

