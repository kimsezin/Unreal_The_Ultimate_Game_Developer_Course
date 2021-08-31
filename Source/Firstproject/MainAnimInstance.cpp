// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"

void UMainAnimInstance::NativeInitializeAnimation()
{
	if (Pawn == nullptr)
	{
		Pawn = TryGetPawnOwner();
	}


}

void UMainAnimInstance::UpdateAnimationProperties()
{

}