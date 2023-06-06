// Fill out your copyright notice in the Description page of Project Settings.


#include "ActivarRagdoll.h"
#include "Components/BoxComponent.h"
#include "Examen2MGNGCharacter.h"

// Sets default values
AActivarRagdoll::AActivarRagdoll()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);
}

// Called when the game starts or when spawned
void AActivarRagdoll::BeginPlay()
{
	Super::BeginPlay();
	
}

void AActivarRagdoll::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AExamen2MGNGCharacter* Character = Cast<AExamen2MGNGCharacter>(OtherActor);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));	
	if(Character!=nullptr)
	{
		Character->GetMesh()->SetAllBodiesBelowSimulatePhysics("pelvis", true);
	}
}

// Called every frame
void AActivarRagdoll::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}