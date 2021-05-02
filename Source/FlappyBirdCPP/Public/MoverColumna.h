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

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Velocidad = 0;
	
	protected:	
		FVector posicionActual = FVector(0,0,0);
	
		UPROPERTY(VisibleAnywhere)
		int movimiento = 0;
	
	public:
		UPROPERTY(EditAnywhere) 
		FVector posicionInicial = FVector(0,0,0);

		UFUNCTION(BlueprintCallable)
		void PruebaFuncionVisibleDesdeBLueprint();
		
	private:
		AActor* columna = nullptr;
		
		

};
