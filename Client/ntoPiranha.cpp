#include "ntoPiranha.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"

namespace nto
{
	Piranha::Piranha()
		: eTick(true)
		, eAttacked(false)
		, eTimer(4.0f)
		, eDeathTime(5.0f)
	{
	}

	Piranha::~Piranha()
	{
	}

	void Piranha::Initialize()
	{
	}

	void Piranha::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (eTick)
		{
			pos.y -= 100.0f * Time::DeltaTime();
			eTimer -= Time::DeltaTime();
			if (eTimer < 0.0f)
			{
				eTimer = 4.0f;
				eTick = false;
			}
		}
		else
		{
			pos.y += 100.0f * Time::DeltaTime();
			eTimer -= Time::DeltaTime();
			if (eTimer < 0.0f)
			{
				eTimer = 4.0f;
				eTick = true;
			}
		}

		tr->SetPosition(pos);
	}

	void Piranha::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Piranha::OnCollisionEnter(Collider* other)
	{
	}

	void Piranha::OnCollisionStay(Collider* other)
	{
	}

	void Piranha::OnCollisionExit(Collider* other)
	{
	}
}
