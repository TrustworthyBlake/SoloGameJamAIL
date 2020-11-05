// Fill out your copyright notice in the Description page of Project Settings.


#include "enemy01.h"

// Sets default values
Aenemy01::Aenemy01()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Aenemy01::BeginPlay()
{
	Super::BeginPlay();

	maxEnemyHP = 100.0f;
	currentEnemyHP = maxEnemyHP;
	enemyHPpercent = 1.0f;
	
}

// Called every frame
void Aenemy01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void Aenemy01::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float Aenemy01::getEnemyHP() {
	return enemyHPpercent;
}

void Aenemy01::updateEnemyHP(float HP) {
	currentEnemyHP += HP;
	currentEnemyHP = FMath::Clamp(currentEnemyHP, 0.0f, maxEnemyHP);
	tempEnemyHP = enemyHPpercent;
	enemyHPpercent = currentEnemyHP / maxEnemyHP;
	UE_LOG(LogTemp, Warning, TEXT("enemy01 hp should update"));
}

void Aenemy01::enemyTakeDamage(float damage) {
	updateEnemyHP(-damage);
}

