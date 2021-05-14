// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "BoxTriggerDestroy.generated.h"

/**
 * 
 */
UCLASS()
class FLAPPYBIRDCPP_API ABoxTriggerDestroy : public ATriggerBox
{
	GENERATED_BODY()

public:
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

protected:
	virtual void BeginPlay() override;
	
	
};
