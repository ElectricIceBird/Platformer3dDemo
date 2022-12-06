// Fill out your copyright notice in the Description page of Project Settings.


#include "DamageBox.h"

#include "AIBOT_CHARACTER.h"
#include "MyAIController.h"

// Sets default values
ADamageBox::ADamageBox()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(Root);

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	Box->SetupAttachment(GetRootComponent());
	Box->OnComponentBeginOverlap.AddDynamic(this,&ADamageBox::OnEnter);
}

void ADamageBox::OnEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep)
{
	AAIBOT_CHARACTER *Char  =Cast<AAIBOT_CHARACTER>(OtherActor);
	if(Char!=nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("CollisionWorking"));
		Char->Damage(damg);
	}
	
}

// Called when the game starts or when spawned
void ADamageBox::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADamageBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADamageBox::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

