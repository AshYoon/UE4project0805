// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/ItemBase.h"

UItemBase::UItemBase()
{


}


UItemBase * UItemBase::CreateItemCopy() const 
{
	// const - > to notice this variable must not change , don't need to change variable -> use const to know 
	// Inventory will make with pointers , try to merge with other items
	// Create whole new object , 



	//if Grab this item , is Template to make a new item 
	UItemBase* ItemCopy = NewObject<UItemBase>(StaticClass());

	ItemCopy->ID = this->ID;
	ItemCopy->Quanity = this->Quanity;
	ItemCopy->ItemQuality = this->ItemQuality;
	ItemCopy->ItemType = this->ItemType;
	ItemCopy->ItemTextData = this->ItemTextData;
	ItemCopy->NumbericData = this->NumbericData;
	ItemCopy->ItemStatisics = this->ItemStatisics;
	ItemCopy->AssetData = this->AssetData;


	return ItemCopy;
}

void UItemBase::SetQuanity(const int32 NewQuanity)
{
	if (NewQuanity != Quanity)
	{
		// if bIsStackable is true , stack size will be numericdata maxstacksize , or false size stackable size is 1
		//
		Quanity = FMath::Clamp(NewQuanity, 0, NumbericData.bIsStackable ? NumbericData.MaxStackSize : 1);


		if (OwningInventory)
		{
			if (Quanity <= 0)
			{
				//amount <= 0 , remove item , it's mean use last item or loose item 
				//OwningInventory->RemoveItem(this);
			}
		}
	}



}

void UItemBase::Use(ACPlayer * Character)
{




}