// Fill out your copyright notice in the Description page of Project Settings.


#include "MoverColumnas.h"

// Sets default values for this component's properties
UMoverColumnas::UMoverColumnas()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoverColumnas::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMoverColumnas::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

