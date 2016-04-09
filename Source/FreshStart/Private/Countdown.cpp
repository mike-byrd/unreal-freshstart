// Fill out your copyright notice in the Description page of Project Settings.

#include "FreshStart.h"
#include "Countdown.h"

#define LOCTEXT_NAMESPACE "FreshStart";

// Sets default values
ACountdown::ACountdown()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	countdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CountdownNumber"));
	countdownText->SetHorizontalAlignment(EHTA_Center);
	countdownText->SetWorldSize(150.0f);
	RootComponent = countdownText;

	countdownTime = 3;
}

// Called when the game starts or when spawned
void ACountdown::BeginPlay()
{
	Super::BeginPlay();
	UpdateTimerDisplay();
	GetWorldTimerManager().SetTimer(countdownTimerHandle, this, &ACountdown::AdvanceTimer, 1.0f, true);
}

// Called every frame
void ACountdown::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ACountdown::UpdateTimerDisplay()
{
	//countdownText->SetText(FString::FromInt(FMath::Max(countdownTime, 0)));
	countdownText->SetText(FText::AsNumber(FMath::Max(countdownTime, 0)));
}

void ACountdown::AdvanceTimer()
{
	--countdownTime;
	UpdateTimerDisplay();
	if (countdownTime < 1)
	{
		//done counting
		GetWorldTimerManager().ClearTimer(countdownTimerHandle);
		CountDownHasFinished();
	}
}

void ACountdown::CountDownHasFinished_Implementation()
{
	//Change to a special readout
	countdownText->SetText(FText::FromString("GO!"));
}

