// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MoverColumna.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FLAPPYBIRDCPP_API UMoverColumna : public UActorComponent
{
		GENERATED_BODY()

	public:	
		// Sets default values for this component's properties
		UMoverColumna();

	protected:
		// Called when the game starts
		virtual void BeginPlay() override;
		
	public:
		virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	protected:
		AActor* column = nullptr;//para hacer referencia a la columna

		UPROPERTY(EditAnywhere)
			int velocityMovement = 5000;//velocidad a la que se va a mover
		UPROPERTY(EditAnywhere)
			FVector displacement = FVector(0, 0, 0); //para calcular el desplazamiento constantemente
		UPROPERTY(EditAnywhere)
			FVector whenItComesRestart = FVector(0, 10000, 0);//cuando llega hasta esta posicion
		UPROPERTY(EditAnywhere)
			FVector resetPosition = FVector(0,-130000,0);// la posicion donde va a reiniciar

};
