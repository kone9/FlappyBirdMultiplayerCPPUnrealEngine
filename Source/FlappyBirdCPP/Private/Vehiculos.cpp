// Fill out your copyright notice in the Description page of Project Settings.


#include "Vehiculos.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AVehiculos::AVehiculos()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootBlueprint = CreateDefaultSubobject<USceneComponent>(TEXT("RootBlueprint"));
	RootComponent = RootBlueprint;
	vehicle = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("NewVehicule"));
	vehicle->AttachTo(RootBlueprint);

}

// Called when the game starts or when spawned
void AVehiculos::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVehiculos::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	vehicle->AddRelativeLocation(vehicle->GetForwardVector() * velocity);//se mueve siempre en direccion hacia el forward
}

