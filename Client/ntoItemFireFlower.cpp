#include "ntoItemFireFlower.h"
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
	ItemFireFlower::ItemFireFlower()
	{
	}

	ItemFireFlower::~ItemFireFlower()
	{
	}

	void ItemFireFlower::Initialize()
	{
	}

	void ItemFireFlower::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		tr->SetPosition(pos);
	}

	void ItemFireFlower::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ItemFireFlower::OnCollisionEnter(Collider* other)
	{
	}

	void ItemFireFlower::OnCollisionStay(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());
		if (player)
		{
			Sound* sound = Resources::Load<Sound>(L"sfxPowerUp", L"..\\Assets\\Sound\\SFX\\WAV\\smw_power-up.wav");
			sound->Play(false);
			Destroy(this);
		}
	}

	void ItemFireFlower::OnCollisionExit(Collider* other)
	{
	}
}
