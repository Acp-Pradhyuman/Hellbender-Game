#pragma once

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	EWT_Snipper UMETA(DisplayName = "Snipper"),
	EWT_AssaultRiffle UMETA(DisplayName = "AssaultRiffle"),

	EWT_MAX UMETA(DisplayName = "DefaultMAX")
};