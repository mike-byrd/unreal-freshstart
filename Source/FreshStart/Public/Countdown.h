// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Countdown.generated.h"

UCLASS()
class FRESHSTART_API ACountdown : public AActor
{
	GENERATED_BODY()

public:
	//How long, in seconds, the countdown will run
	UPROPERTY(EditAnywhere)
	int32 countdownTime;
	FTimerHandle countdownTimerHandle;
	UTextRenderComponent* countdownText;
	
public:	
	// Sets default values for this actor's properties
	ACountdown();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	void UpdateTimerDisplay();
	void AdvanceTimer();

	UFUNCTION(BlueprintNativeEvent)
	void CountDownHasFinished();	
	virtual void CountDownHasFinished_Implementation();
};
