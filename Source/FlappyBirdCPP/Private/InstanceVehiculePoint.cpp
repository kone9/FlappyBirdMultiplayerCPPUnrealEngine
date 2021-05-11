// Fill out your copyright notice in the Description page of Project Settings.


#include "InstanceVehiculePoint.h"
#include "Engine/World.h"
#include "TimerManager.h"

// Sets default values
AInstanceVehiculePoint::AInstanceVehiculePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootOfBlueprint = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponentOfBlueprint"));
	RootComponent = RootOfBlueprint;

}

// Called when the game starts or when spawned
void AInstanceVehiculePoint::BeginPlay()
{
	Super::BeginPlay();

	instanceVehicules();//instancio un vehiculo al iniciar

	GetWorldTimerManager().SetTimer(cronometro, this, &AInstanceVehiculePoint::instanceVehicules, timpoAinstanciar, true);//instancia un vehiculo cada cierto tiempo
	
}

// Called every frame
void AInstanceVehiculePoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//para instanciar un vehiculo dentro de una lista de forma aleatorio
void AInstanceVehiculePoint::instanceVehicules()
{
	//putero a un objeto de arreglo para instanciar aleatoriamente
	TSubclassOf<AActor> vehiculoAleatorio = vehiculesAInstance[ FMath::RandRange ( 0, vehiculesAInstance.Num() -1 )];
	
	AActor* vehiculoenEscena =  GetWorld()->SpawnActor<AActor>(vehiculoAleatorio, GetActorLocation(), GetActorRotation());//instancia a la escena
	vehiculoenEscena->AttachToActor(rootDeTodosLosVehiculos, FAttachmentTransformRules::KeepWorldTransform);
																														  //if (rootDeTodosLosVehiculos != nullptr)
	//{
	//	vehiculoenEscena->AttachToActor(vehiculoenEscena,rootDeTodosLosVehiculos);//hago que sea hijo de ese actor en escena
	//}
	//GetWorld()->SpawnActor<AActor>(vehiculesAInstance[FMath::RandRange(0, vehiculesAInstance.Num() - 1)], GetActorLocation(), GetActorRotation());//instancia a la escena
}

