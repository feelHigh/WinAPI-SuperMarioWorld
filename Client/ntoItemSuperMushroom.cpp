#include "ntoItemSuperMushroom.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"
#include "ntoResources.h"
#include "ntoSound.h"

namespace nto
{
	ItemSuperMushroom::ItemSuperMushroom()
	{
	}

	ItemSuperMushroom::~ItemSuperMushroom()
	{
	}

	void ItemSuperMushroom::Initialize()
	{
	}

	void ItemSuperMushroom::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);
	}

	void ItemSuperMushroom::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ItemSuperMushroom::OnCollisionEnter(Collider* other)
	{
	}

	void ItemSuperMushroom::OnCollisionStay(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player)
		{
			Sound* sound = Resources::Load<Sound>(L"sfxPowerUp", L"..\\Assets\\Sound\\SFX\\WAV\\smw_power-up.wav");
			sound->Play(false);
			Destroy(this);
		}
	}

	void ItemSuperMushroom::OnCollisionExit(Collider* other)
	{
	}
}
