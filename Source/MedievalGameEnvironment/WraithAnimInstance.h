// Licensed for use with Unreal Engine products only

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "WraithAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class MEDIEVALGAMEENVIRONMENT_API UWraithAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
	void UpdateAnimationProperties(float DeltaTime);

private:
	//lateral movement speed
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class AEnemy* Enemy;
	
};
