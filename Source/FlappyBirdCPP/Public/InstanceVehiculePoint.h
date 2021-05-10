// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstanceVehiculePoint.generated.h"

UCLASS()
class FLAPPYBIRDCPP_API AInstanceVehiculePoint : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstanceVehiculePoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	UPROPERTY()
		class USceneComponent* RootOfBlueprint;//el blueprint root

	UPROPERTY(EditAnywhere)
		TArray< TSubclassOf<AActor> > vehiculesAInstance;//array de blueprint de los archivos
	
	UPROPERTY(EditAnywhere)
	float timpoAinstanciar = 2.5f;//el tiempo a instanciar

	FTimerHandle cronometro;//para el timer instanciar
	
	void instanceVehicules();//para instanciar los vehiculos
};
