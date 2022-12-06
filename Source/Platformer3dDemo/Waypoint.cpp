// Fill out your copyright notice in the Description page of Project Settings.


#include "Waypoint.h"

#include "AIBOT_CHARACTER.h"

// Sets default values
AWaypoint::AWaypoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root Component"));
	SetRootComponent(Root);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Box"));
	BoxComponent->SetupAttachment(GetRootComponent());
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this,&AWaypoint::OnPlayerEnter);

}


// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWaypoint::OnPlayerEnter(UPrimitiveComponent* OverlapComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& Sweep)
{
		AAIBOT_CHARACTER*Character = nullptr;
	if(OtherActor!=nullptr)
	{
		Character=Cast<AAIBOT_CHARACTER>(OtherActor);
		if(Character!=nullptr)
		{
			Character->NextWayPoint = NextWayPoint;
		}
	}
}
