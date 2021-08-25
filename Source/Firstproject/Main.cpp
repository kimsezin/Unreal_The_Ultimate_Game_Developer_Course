// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ī�޶� �� (��������, �÷��̾ �浹�� ������ ����.)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.0f; // ī�޶�� �÷��̾ �Ÿ�
	CameraBoom->bUsePawnControlRotation = true; // ��Ʈ�ѷ� �������� ȸ��

	// ����ٴϴ� ī�޶� ����
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); //���� �������Ͽ��� ������ ���� ���� �پ�����, �������Ͽ� ī�޶� ����
	// let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // ī�޶�� ����
	
	// Set our turn rate for input
	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMain::MoveForward(float value)
{
	if ((Controller != nullptr) && (value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	}
}

void AMain::MoveRight(float value)
{

}

