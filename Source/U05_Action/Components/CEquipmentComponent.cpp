// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/CEquipmentComponent.h"

// Sets default values for this component's properties
UCEquipmentComponent::UCEquipmentComponent()
{

	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UCEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}




void UCEquipmentComponent::SetEquipment(F_Item * item)
{





}

void UCEquipmentComponent::RemoveEquipment(E_ItemType Type)
{
}

// Called every frame
void UCEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

