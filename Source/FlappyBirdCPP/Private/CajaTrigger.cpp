// Fill out your copyright notice in the Description page of Project Settings.


#include "CajaTrigger.h"
#include "DrawDebugHelpers.h"


//Metodo contructor
ACajaTrigger::ACajaTrigger()
{
}

//metodo beginPlay
void ACajaTrigger::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("inicio el juego!"));
	
	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Purple, true, -1, 0, 100);
	
	OnActorBeginOverlap.AddDynamic(this, &ACajaTrigger::OnOverlapBegin);//siempre declarar la dinamica del overlapBegin, coloco en metodo contructor porque es de este tipo, sino ojo conviene en beginPlay

}

void ACajaTrigger::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
	if (OtherActor != nullptr)
	{
		OtherActor->Destroy();
	}
	if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("entro un cuerpo al area!"));
	
	/*if (OtherActor && (OtherActor != this))
	{

	}*/
}
