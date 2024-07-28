// Licensed for use with Unreal Engine products only

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WhipHitInterface.h"
#include "Teleported.generated.h"

UCLASS()
class MEDIEVALGAMEENVIRONMENT_API ATeleported : public AActor, public IWhipHitInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleported();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	//teleportation when hit by whip
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	UParticleSystem* TeleportParticles;

	//sound to play when hit by whip
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Combat, meta = (AllowPrivateAccess = "true"))
	class USoundCue* ImpactSound;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void WhipHit_Implementation(FHitResult HitResult) override;

};
