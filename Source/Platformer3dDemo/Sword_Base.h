// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Sword_Base.generated.h"


UCLASS()
class PLATFORMER3DDEMO_API ASword_Base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASword_Base();
	UPROPERTY(EditAnywhere,BlueprintReadOnly)
	float swordDamage;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	AActor * TheOwner = GetOwner();

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
