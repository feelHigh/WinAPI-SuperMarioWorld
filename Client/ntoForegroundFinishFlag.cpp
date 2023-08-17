#include "ntoForegroundFinishFlag.h"
#include "Player.h"
#include "Transform.h"
#include "Animator.h"
#include "SpriteRenderer.h"
#include "ntoCollider.h"
#include "ntoRigidbody.h"
#include "CustomTime.h"
#include "SceneManager.h"
#include "StageWorldMap.h"
#include "Camera.h"

namespace nto
{
	ForegroundFinishFlag::ForegroundFinishFlag()
		: bTimer(3.0f)
		, bTick(true)
	{
	}

	ForegroundFinishFlag::~ForegroundFinishFlag()
	{
	}

	void ForegroundFinishFlag::Initialize()
	{
	}

	void ForegroundFinishFlag::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (bTick)
		{
			pos.y += 170.0f * Time::DeltaTime();
			bTimer -= Time::DeltaTime();
			if (bTimer < 0.0f)
			{
				bTimer = 3.0f;
				bTick = false;
			}
		}
		else
		{
			pos.y -= 170.0f * Time::DeltaTime();
			bTimer -= Time::DeltaTime();
			if (bTimer < 0.0f)
			{
				bTimer = 3.0f;
				bTick = true;
			}
		}

		tr->SetPosition(pos);

		SpriteRenderer* sr = GetComponent<SpriteRenderer>();
	}

	void ForegroundFinishFlag::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void ForegroundFinishFlag::OnCollisionEnter(Collider* other)
	{
	}

	void ForegroundFinishFlag::OnCollisionStay(Collider* other)
	{
		Player* player = dynamic_cast<Player*>(other->GetOwner());

		if (player)
		{
			Destroy(this);
			Camera::SetTarget(nullptr);
			Camera::SetOffset(Vector2(0.0f, 0.0f));

			SceneManager::LoadScene(L"StageWorldMap");
		}
	}

	void ForegroundFinishFlag::OnCollisionExit(Collider* other)
	{
	}
}
