// Fill out your copyright notice in the Description page of Project Settings.


#include "BoxTriggerDestroy.h"

void ACajaTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	
	if (OtherActor != nullptr)//como son punteros siempre verificar que no sea nulo
	{
		if (OtherActor->ActorHasTag("obstacleVehicule"))//si tiene la etiqueta obstacleVehicule
		{
			OtherActor->Destroy();
		}
	}
}