// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTriggerComponent::BeginPlay()
{
    Super::BeginPlay();

    if(MoverActor)
    {
        Mover = MoverActor->FindComponentByClass<UMover>();
   //     if(Mover){
   //         UE_LOG(LogTemp, Warning, TEXT("Succesfully found the mover component"));
			//Mover->bShouldMove = true;
   //     }
   //     else {
   //         UE_LOG(LogTemp, Warning, TEXT("not found the mover component"));
   //     }
    }else
    {
        UE_LOG(LogTemp, Warning, TEXT("MoverActor is not set in TriggerComponent"));
    }

    if(!IsPressurePlate){
        OnComponentBeginOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapBegin);
        OnComponentEndOverlap.AddDynamic(this, &UTriggerComponent::OnOverlapEnd);
    }
}

void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTriggerComponent::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if(Mover)
    {
        Mover->bShouldMove = true;
    }
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if(Mover)
    {
        Mover->bShouldMove = false;
    }
}