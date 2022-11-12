//Fill out your copyright notice in the Description page of Project Settings.


#include "ZU.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AZU::AZU()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GetCapsuleComponent()-> InitCapsuleSize(42.0f,96.0f);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f,540.0f,0.0f);
	GetCharacterMovement()->JumpZVelocity= 600.0f;
	GetCharacterMovement()->AirControl = .2f;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom -> SetupAttachment(RootComponent);

	CameraBoom-> TargetArmLength = 300.0f; 
	CameraBoom-> bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera -> SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera -> bUsePawnControlRotation = false;

	bDead = false;
	power = 100.0f;
		
}

// Called when the game starts or when spawned
void AZU::BeginPlay()
{
	Super::BeginPlay();
	// const FVector Loc = GetActorLocation();
	// const FRotator Roc = GetActorRotation();
	// FVector SocketLocationL;
	// GetWorld()->SpawnActor<AActor>(Sword,Loc,Roc);
	//
	
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this,&AZU::OnBeginOverlap);
	if(Player_Power_Widget_Class != nullptr)
	{
		Player_Power_Widget = CreateWidget(GetWorld(),Player_Power_Widget_Class);
		Player_Power_Widget-> AddToViewport();
		
	}
	
}

// Called every frame
void AZU::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	power-= DeltaTime * Power_Treshold;
	if(power<=0)
	{
		if(!bDead)
		{
			bDead=true;
			GetMesh()->SetSimulatePhysics(true);

			FTimerHandle UnusedHandle;
			GetWorldTimerManager().SetTimer(
				UnusedHandle,this,&AZU::RestartGame,3.0f,false
			);
			


		}
	}

}

// Called to bind functionality to input
void AZU::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Turn",this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp",this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAction("Jump",IE_Pressed,this,&ACharacter::Jump );
	PlayerInputComponent->BindAction("Jump",IE_Released,this,&ACharacter::StopJumping);

		PlayerInputComponent->BindAxis("MoveForward",this, &AZU::MoveForward);
		PlayerInputComponent->BindAxis("MoveRight",this, &AZU::MoveRight);
		PlayerInputComponent->BindAction("Attack",IE_Pressed,this,&AZU::Attack);


	
	



}

void AZU::MoveForward(float Axis)
	{
		if(!bDead){
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0,Rotation.Yaw,0);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
			AddMovementInput(Direction,Axis);
		}	
	}
void AZU::MoveRight(float Axis)
	{

		if(!bDead){
			const FRotator Rotation = Controller->GetControlRotation();
			const FRotator YawRotation(0,Rotation.Yaw,0);
			const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
			AddMovementInput(Direction,Axis);
		}

		
	}
void AZU::Attack()
{
	if(AttackAnim)
	{
		
		PlayAnimMontage(AttackAnim,1,NAME_None);	
	}
}	
void AZU::RestartGame()
{

	UGameplayStatics::OpenLevel(this,FName(*GetWorld()->GetName()),false);


}
void AZU::OnBeginOverlap(class UPrimitiveComponent*HitComp,class AActor* OtherActor, 
class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)	
{

	if(OtherActor->ActorHasTag("PickUp")){
		
		power+=10.0f;
		if(power> 100.0f)
		{
			power = 100.0f;
		}
		OtherActor->Destroy();


	}


}



