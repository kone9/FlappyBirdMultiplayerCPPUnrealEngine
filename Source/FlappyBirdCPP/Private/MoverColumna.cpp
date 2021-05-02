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
	columna  = GetOwner();// la columna es uno mismo
	
}


// Called every frame
void UMoverColumna::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	// ...
}

void UMoverColumna::PruebaFuncionVisibleDesdeBLueprint()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Hola mundo desde C++ en un blueprint"));
	
}

