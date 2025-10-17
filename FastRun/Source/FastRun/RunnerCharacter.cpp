// Fill out your copyright notice in the Description page of Project Settings.


#include "RunnerCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/InputComponent.h"
// Sets default values
ARunnerCharacter::ARunnerCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
}

void ARunnerCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // í‚É‘O•ûŒü‚ÉˆÚ“®
    AddMovementInput(GetActorForwardVector(), ForwardSpeed * DeltaTime);

    // ¶‰EƒŒ[ƒ“ˆÚ“®ˆ—
    UpdateLaneMovement(DeltaTime);
}

void ARunnerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    Super::SetupPlayerInputComponent(PlayerInputComponent);
    PlayerInputComponent->BindAction("MoveLeft", IE_Pressed, this, &ARunnerCharacter::MoveLeft);
    PlayerInputComponent->BindAction("MoveRight", IE_Pressed, this, &ARunnerCharacter::MoveRight);
}

void ARunnerCharacter::MoveLeft()
{
    if (CurrentLane > -1)
    {
        CurrentLane--;
        TargetLocation = GetActorLocation() + FVector(0, -LaneOffset, 0);
    }
}

void ARunnerCharacter::MoveRight()
{
    if (CurrentLane < 1)
    {
        CurrentLane++;
        TargetLocation = GetActorLocation() + FVector(0, LaneOffset, 0);
    }
}

void ARunnerCharacter::UpdateLaneMovement(float DeltaTime)
{
    FVector CurrentLocation = GetActorLocation();
    FVector DesiredLocation = FVector(CurrentLocation.X, CurrentLane * LaneOffset, CurrentLocation.Z);
    FVector NewLocation = FMath::VInterpTo(CurrentLocation, DesiredLocation, DeltaTime, 10.f);
    SetActorLocation(NewLocation);
}