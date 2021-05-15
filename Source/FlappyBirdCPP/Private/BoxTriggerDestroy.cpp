// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxTriggerDestroy.h"

void ABoxTriggerDestroy::BeginPlay()
{
	OnActorBeginOverlap.AddDynamic(this, &ABoxTriggerDestroy::OnOverlapBegin);
}

void ABoxTriggerDestroy::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	//if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("Entro un vehiculo y tendría que destruirse!"));
	if (OtherActor != nullptr)//como son punteros siempre verificar que no sea nulo
	{
		if (OtherActor->ActorHasTag("obstacleVehicule"))//si tiene la etiqueta obstacleVehicule
		{
			OtherActor->Destroy();
		}
	}
}