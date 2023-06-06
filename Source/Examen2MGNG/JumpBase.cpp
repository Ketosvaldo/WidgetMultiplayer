// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpBase.h"
#include "Components/BoxComponent.h"
#include "Examen2MGNGCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AJumpBase::AJumpBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);

	DashMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DashMesh"));
	DashMesh->SetupAttachment(BoxCollision);
}

// Called when the game starts or when spawned
void AJumpBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void AJumpBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));	
	AExamen2MGNGCharacter* Character = Cast<AExamen2MGNGCharacter>(OtherActor);
	if(Character != nullptr)
	{
		Character->canMove = true;
		Character->GetCharacterMovement()->Velocity = FVector(0,0,0);
		Character->GetCharacterMovement()->AddImpulse(FVector(0,0,200000.f));
	}
}

// Called every frame
void AJumpBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

