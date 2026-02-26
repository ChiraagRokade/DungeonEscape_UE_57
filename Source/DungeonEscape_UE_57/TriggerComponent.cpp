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
    if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator")) {
		ActivatorCount++;
        if (!bIsTriggered) {
            Trigger(true);
        }
    }
}

void UTriggerComponent::OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (OtherActor && OtherActor->ActorHasTag("PressurePlateActivator")) {
        ActivatorCount--;
        if(bIsTriggered && (ActivatorCount==0)){
            Trigger(false);
		}
    }
}

void UTriggerComponent::Trigger(bool NewTriggeredState)
{
    bIsTriggered = NewTriggeredState;
    if (Mover)
    {
        Mover->SetShouldMove(bIsTriggered);
    }
}