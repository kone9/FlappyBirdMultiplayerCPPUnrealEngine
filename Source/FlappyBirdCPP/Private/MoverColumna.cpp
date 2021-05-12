// Fill out your copyright notice in the Description page of Project Settings.

#include "MoverColumna.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UMoverColumna::UMoverColumna()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UMoverColumna::BeginPlay()
{
	Super::BeginPlay();

	// ...
	column = GetOwner();// la columna es uno mismo
	
}


// Called every frame
void UMoverColumna::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
	displacement.Y = velocityMovement * DeltaTime;//calcula el movimiento en el eje y

	column->AddActorLocalOffset(displacement);//mueve constantemente
}



