// Fill out your copyright notice in the Description page of Project Settings.


#include "InstanceVehiculePoint.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Components/ArrowComponent.h"

// Sets default values
AInstanceVehiculePoint::AInstanceVehiculePoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootOfBlueprint = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponentOfBlueprint"));
	RootComponent = RootOfBlueprint;
	//I create the arrows to use as a guide to position the instances
	left = CreateDefaultSubobject<UArrowComponent>(TEXT("left"));
	right = CreateDefaultSubobject<UArrowComponent>(TEXT("right"));
	up = CreateDefaultSubobject<UArrowComponent>(TEXT("up"));
	down = CreateDefaultSubobject<UArrowComponent>(TEXT("down"));
	//they are children of rootBlueprint
	left->AttachTo(RootOfBlueprint);
	right->AttachTo(RootOfBlueprint);
	up->AttachTo(RootOfBlueprint);
	down->AttachTo(RootOfBlueprint);

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
	
	//random position taking into account the arrows
	FVector aleatoryPosition = FVector(
		GetActorLocation().X,
		FMath::RandRange(left->GetComponentToWorld().GetLocation().Y, right->GetComponentToWorld().GetLocation().Y),
		FMath::RandRange(down->GetComponentToWorld().GetLocation().Z, up->GetComponentToWorld().GetLocation().Z)
	);

	//random position taking into account the arrows "Component local position"
	FVector aleatoryLocalPosition = FVector(
		GetActorLocation().X,
		FMath::RandRange(left->GetComponentLocation().Y, right->GetComponentLocation().Y),
		FMath::RandRange(down->GetComponentLocation().Z, up->GetComponentLocation().Z)
	);
	

	AActor* vehiculoenEscena =  GetWorld()->SpawnActor<AActor>(vehiculoAleatorio, aleatoryLocalPosition, GetActorRotation());//instancia a la escena
	vehiculoenEscena->AttachToActor(rootDeTodosLosVehiculos, FAttachmentTransformRules::KeepWorldTransform);
	vehiculoenEscena->Tags.Add("obstacleVehicule");//agrego el tag a ese nuevo vehiculo
/*	InstancedVehiclesList.Add(vehiculoenEscena);	*/																								  //if (rootDeTodosLosVehiculos != nullptr)
	//{
	//	vehiculoenEscena->AttachToActor(vehiculoenEscena,rootDeTodosLosVehiculos);//hago que sea hijo de ese actor en escena
	//}
	//GetWorld()->SpawnActor<AActor>(vehiculesAInstance[FMath::RandRange(0, vehiculesAInstance.Num() - 1)], GetActorLocation(), GetActorRotation());//instancia a la escena
}

