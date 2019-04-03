// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseWeapon.h"
#include "Runtime/Engine/Classes/Components/SkeletalMeshComponent.h"


// Sets default values
ABaseWeapon::ABaseWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	this->bReplicates = true;
	this->bReplicateMovement = true;

	//Setup the first person part of the gun
	FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_GUN"));
	FP_Gun->SetOnlyOwnerSee(true);
	SetRootComponent(FP_Gun);
	

	// And also its third person elements :)
	TP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TP_GUN"));
	TP_Gun->SetOwnerNoSee(true);
	TP_Gun->SetupAttachment(FP_Gun);
}

// Called when the game starts or when spawned
void ABaseWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UFUNCTION(BlueprintCallable)
USkeletalMeshComponent* ABaseWeapon::getFPGun() const
{
	return FP_Gun;
}

UFUNCTION(BlueprintCallable)
USkeletalMeshComponent* ABaseWeapon::getTPGun() const
{
	return TP_Gun;
}
