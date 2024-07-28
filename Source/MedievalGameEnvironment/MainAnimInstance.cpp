// Licensed for use with Unreal Engine products only


#include "MainAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Main.h"
#include "Kismet/KismetMathLibrary.h"
#include "Weapon.h"

UMainAnimInstance::UMainAnimInstance() :
	Speed(0.f),
	bIsInAir(false),
	bIsAccelerating(false),
	MovementOffsetYaw(0.f),
	LastMovementOffsetYaw(0.f),
	EquippedWeaponType(EWeaponType::EWT_MAX),
	bShouldUseFABRIK(false)
{

}

void UMainAnimInstance::NativeInitializeAnimation()
{
	MainCharacter = Cast<AMain>(TryGetPawnOwner());
}

void UMainAnimInstance::UpdateAnimationProperties(float DeltaTime)
{
	if (MainCharacter == nullptr)
	{
		MainCharacter = Cast<AMain>(TryGetPawnOwner());
	}
	if (MainCharacter)
	{
		bShouldUseFABRIK = MainCharacter->GetCombatState() == ECombatState::ECS_Unoccupied || MainCharacter->GetCombatState() == ECombatState::ECS_FireTimerInProgress;

		//get the lateral speed of the character
		FVector Velocity{ MainCharacter->GetVelocity() };
		Velocity.Z = 0;
		Speed = Velocity.Size();

		//is the character in the air?
		bIsInAir = MainCharacter->GetCharacterMovement()->IsFalling();
		if (MainCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			bIsAccelerating = true;
		}
		else
		{
			bIsAccelerating = false;
		}

		FRotator AimRotation = MainCharacter->GetBaseAimRotation();
		FRotator MovementRotation = UKismetMathLibrary::MakeRotFromX(MainCharacter->GetVelocity());
		MovementOffsetYaw = UKismetMathLibrary::NormalizedDeltaRotator(MovementRotation, AimRotation).Yaw;
		if (bIsAccelerating)
		{
			LastMovementOffsetYaw = MovementOffsetYaw;
		}
		//check if the main character has a valid equipped weapon
		if (MainCharacter->GetEquippedWeapon())
		{
			EquippedWeaponType = MainCharacter->GetEquippedWeapon()->GetWeaponType();
		}
	}
}



