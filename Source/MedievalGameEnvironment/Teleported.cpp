// Licensed for use with Unreal Engine products only


#include "Teleported.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ATeleported::ATeleported()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATeleported::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATeleported::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleported::WhipHit_Implementation(FHitResult HitResult)
{

	if (ImpactSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, ImpactSound, GetActorLocation());
	}
	if (TeleportParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), TeleportParticles, HitResult.Location, FRotator(0.f), true);
	}

	Destroy();
}

