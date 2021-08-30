// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"

UCLASS()
class FIRSTPROJECT_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

	/** Camera boom�� �÷��̾� �ڿ� ��ġ */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true")) //�������Ʈ ���ο��� �׼��� ����, �ܺο��� �׼��� �Ұ�
	class USpringArmComponent* CameraBoom;
	
	/** ����ٴϴ� ī�޶� */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Base turn rates to scale turning functions for the camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** called for forwards//backwards input */
	void MoveForward(float value);

	/** called for side to side input */
	void MoveRight(float value);

	/** Called via input to turn at a given rate
	* @param Rate This is a normalize rate, i.e. 1.0means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/** Called via input to look up/down at a given rate
	* @param Rate This is a normalize rate, i.e. 1.0means 100% of desired look up/rate rate
	*/
	void LookUpAtRate(float Rate);

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};
