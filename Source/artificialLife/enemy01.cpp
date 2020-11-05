// Fill out your copyright notice in the Description page of Project Settings.


#include "enemy01.h"
#include "Blueprint/UserWidget.h"
#include "UObject/ConstructorHelpers.h"
#include "CanvasItem.h"

// Sets default values
Aenemy01::Aenemy01()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//static ConstructorHelpers::FClassFinder<UUserWidget> HealthBarObj(TEXT("/Game/enemyUI/enemyHPbar"));
	//HUDWidgetClass2 = HealthBarObj.Class;
}

// Called when the game starts or when spawned
void Aenemy01::BeginPlay()
{
	Super::BeginPlay();

	maxEnemyHP = 100.0f;
	currentEnemyHP = maxEnemyHP;
	enemyHPpercent = 1.0f;
	
	/*if (HUDWidgetClass2 != nullptr) {
		enemyHPWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass2);

		if (enemyHPWidget) {
			enemyHPWidget->AddToViewport();
		}
	}*/
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

