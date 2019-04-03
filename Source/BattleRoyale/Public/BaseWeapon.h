// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseWeapon.generated.h"

UCLASS()
class BATTLEROYALE_API ABaseWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	UFUNCTION(BlueprintPure)
	class USkeletalMeshComponent* getFPGun() const;

	UFUNCTION(BlueprintPure)
	class USkeletalMeshComponent* getTPGun() const;

protected:
	
	// Holds the damage dealt by weapon
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		float fDamage = 30.0f;
	// Holds weapons name
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = Weapon)
		FString sWeaponName = "BaseWep";

	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* FP_Gun = nullptr;;

	/** Gun mesh in 3rd person (seen by enemies) */
	UPROPERTY(EditDefaultsOnly, Category = Mesh)
		class USkeletalMeshComponent* TP_Gun = nullptr;;

	
	
};
