#include "Actions/CAttachment.h"
#include "Global.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CStateComponent.h"
#include "Components/CStatusComponent.h"
#include "Components/ShapeComponent.h"

ACAttachment::ACAttachment()
{


}


void ACAttachment::BeginPlay()
{

	OwnerCharacter = Cast<ACharacter>(GetOwner());
	State = CHelpers::GetComponent<UCStateComponent>(OwnerCharacter);
	Status = CHelpers::GetComponent<UCStatusComponent>(OwnerCharacter);


	// �浹ü�� �ϳ��ϼ��������� �ƴҼ����ִ� 
	// Fist�� �浹ü�� 4�� �ϱ� ShapeComponent�������� �ִ°� �� �����ϴ°Ŵ� 
	GetComponents<UShapeComponent>(ShapeComponents);
	for (UShapeComponent* component : ShapeComponents)
	{
		component->OnComponentBeginOverlap.AddDynamic(this, &ACAttachment::OnComponentBeginOverlap);
		component->OnComponentEndOverlap.AddDynamic(this, &ACAttachment::OnComponentEndOverlap);
	}







	OffCollision();
	Super::BeginPlay();
	
}

void ACAttachment::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �ڱ��ڽ��� �浹�ϸ�ȵǴϱ� �׺κ� üũ 
	CheckTrue(OwnerCharacter == OtherActor);
	CheckTrue(OtherActor->GetClass() == OwnerCharacter->GetClass());


	// ��������Ʈ ���� 
	if (OnAttamentBeginOverlap.IsBound())
		OnAttamentBeginOverlap.Broadcast(OwnerCharacter, this, Cast<ACharacter>(OtherActor));


}

void ACAttachment::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{


	if (OnAttamentEndOverlap.IsBound())
		OnAttamentEndOverlap.Broadcast(OwnerCharacter, this, Cast<ACharacter>(OtherActor));
}

void ACAttachment::AttachTo(FName InSocketName)
{
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), InSocketName);
}

void ACAttachment::AttachToCollision(UShapeComponent* InComponent, FName InSocketName)
{
	InComponent->AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), InSocketName);
}



void ACAttachment::OnCollision()
{
	for (UShapeComponent* component : ShapeComponents)
		component->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	if (OnAttachmentCollision.IsBound())
		OnAttachmentCollision.Broadcast();
}

void ACAttachment::OffCollision()
{
	for (UShapeComponent* component : ShapeComponents)
		component->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if (OffAttachmentCollision.IsBound())
		OffAttachmentCollision.Broadcast();
}