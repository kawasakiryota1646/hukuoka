// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RunnerCharacter.generated.h"

UCLASS()
class FASTRUN_API ARunnerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARunnerCharacter();

protected:
    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditAnywhere, Category = "Movement")
    float ForwardSpeed = 600.f; // 1�b������̑O�i���x

    UPROPERTY(EditAnywhere, Category = "Movement")
    float LaneOffset = 300.f; // ���[���̊Ԋu�i���E�ړ��p�j

    int CurrentLane = 0; // -1, 0, 1 ��3���[�����ɂ����

    void MoveLeft();
    void MoveRight();

    FVector TargetLocation;
    void UpdateLaneMovement(float DeltaTime);

    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};
