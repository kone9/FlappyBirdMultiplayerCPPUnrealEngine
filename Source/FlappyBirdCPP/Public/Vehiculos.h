// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Vehiculos.generated.h"

UCLASS()
class FLAPPYBIRDCPP_API AVehiculos : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehiculos();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
	class USceneComponent* RootBlueprint;//el blueprint root

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* vehicle;//el vehiculo que va a representar

	UPROPERTY(EditAnywhere)
	int velocity = 1;//velocidad del vehiculo


};
