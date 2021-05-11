// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "CajaTrigger.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRDCPP_API ACajaTrigger : public ATriggerBox
{
	GENERATED_BODY()

public:
	ACajaTrigger();//metodo contructor

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
		bool leftPosition = false;//posicion izquierda
	UPROPERTY(EditAnywhere)
		bool rightPosition = false;//posicion Derecho
	UPROPERTY(EditAnywhere)
		bool forwardPosition = false;//posicion Adelante
	UPROPERTY(EditAnywhere)
		bool backPosition = false;//posicion Atras
	UPROPERTY(EditAnywhere)
	class AActor* posicionReinicio;

private:
	void PositionAccordingtoPositionReset(class AActor* OtherActor);//acomodar segun posicion
	
};
