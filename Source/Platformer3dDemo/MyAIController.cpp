// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"

#include "AIBOT_CHARACTER.h"
#include "Waypoint.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
AMyAIController::AMyAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception")));

	SightConfig->SightRadius = AISightRadius;
	SightConfig->LoseSightRadius = AILoseSightRadius;
	SightConfig->PeripheralVisionAngleDegrees= AIFieldOfView;
	SightConfig->SetMaxAge(AISightAge);

	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());
	GetPerceptionComponent()->OnPerceptionUpdated.AddDynamic(this,&AMyAIController::OnPawnDetected);
	GetPerceptionComponent()->ConfigureSense(*SightConfig);

	
}

void AMyAIController::BeginPlay()
{
	Super::BeginPlay();
	if(GetPerceptionComponent() != nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("ALL SYSTEM GOOD"));
	}else
	{
		UE_LOG(LogTemp,Warning,TEXT("ALL NOT SYSTEM GOOD"));
		
	}
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
}

void AMyAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AAIBOT_CHARACTER *Chara = Cast<AAIBOT_CHARACTER>(GetPawn());
	if(Chara->NextWayPoint != nullptr)
	{
		MoveToActor(Chara->NextWayPoint,5.0f);
	}
}

FRotator AMyAIController::GetControlRotation() const
{
	if(GetPawn()==nullptr)
	{
		return FRotator(0.0f,0.0f,0.0f);
	}
	return FRotator(0.0f,GetPawn()->GetActorRotation().Yaw,0.0f);
}

void AMyAIController::OnPawnDetected(const TArray<AActor*>& DetectedPawns)
{
	
}
