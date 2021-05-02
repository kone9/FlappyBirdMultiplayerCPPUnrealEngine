// Fill out your copyright notice in the Description page of Project Settings.


#include "PajaroCpp.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APajaroCpp::APajaroCpp()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APajaroCpp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APajaroCpp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APajaroCpp::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction("ClickIzqueirdo", IE_Pressed, this, &APajaroCpp::Impulsar);
}

void APajaroCpp::Impulsar()
{

	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, FString::Printf(TEXT("Hola clase hija")));
	// (UStaticMeshComponent)pajaro->AddImpulse(FVector(0,fuerzaImpulso,0));
	// UStaticMeshComponent* pajaroNuevo;
	// pajaroNuevo->AddImpulse(FVector(0,fuerzaImpulso,0));

}

