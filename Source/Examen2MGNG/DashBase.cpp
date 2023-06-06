// Fill out your copyright notice in the Description page of Project Settings.


#include "DashBase.h"
#include "Examen2MGNGCharacter.h"
#include "Components/BoxComponent.h"
#include "Math/Rotator.h"

// Sets default values
ADashBase::ADashBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxCollision;
	BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OverlapBegin);

	DashMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DashMesh"));
	DashMesh->SetupAttachment(BoxCollision);

	ArrowDirection = CreateDefaultSubobject<UArrowComponent>(TEXT("ArrowDirection"));
	ArrowDirection->SetupAttachment(DashMesh);

	bSpeed = 50.0f;
}

// Called when the game starts or when spawned
void ADashBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADashBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	BoxCollision->SetWorldLocation(DashMesh->GetComponentLocation());

}

void ADashBase::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AExamen2MGNGCharacter* Character = Cast<AExamen2MGNGCharacter>(OtherActor);
	if(GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Some debug message!"));	
	if(Character != nullptr)
	{
		Character->canMove = false;
		Character->SetArrowDirection(ArrowDirection->GetComponentRotation().Vector());
		Character->moveCounter = 2.f;
	}
}

