#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CUserWidget_ActionList.generated.h"

// ��Ƽĳ��Ʈ�� ������� �浹�Ǿ����� ! ������� �̺�Ʈ�ϱ� 
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FUserWidget_ActionItem_Clicked);

USTRUCT(BlueprintType)
struct FUserWidget_Action_Data
{
	GENERATED_BODY()
		// Action Data ������ ����ü 
public:
	class UCUserWidget_ActionItem* Item;
	FUserWidget_ActionItem_Clicked OnUserWidget_ActionItem_Clicked;
};



UCLASS()
class U05_ACTION_API UCUserWidget_ActionList : public UUserWidget
{
	GENERATED_BODY()
public:
	FORCEINLINE FUserWidget_Action_Data& GetData(uint32 InIndex) { return Datas[InIndex]; }

protected:
	virtual void NativeConstruct() override; // NativeConstruct -���� �⺻ ������ 

public:
	void Clicked(FString InName);
	void Hovered(FString InName);
	void Unhovered(FString InName);

private:
	TArray<FUserWidget_Action_Data> Datas;


};