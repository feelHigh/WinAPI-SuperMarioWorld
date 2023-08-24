#include "ntoRedPara.h"
#include "ntoRedKoopa.h"
#include "ntoRedShell.h"
#include "Player.h"
#include "ntoRedKoopa.h"
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
	RedPara::RedPara()
		: mRotateTime(5.0f)
		, mDeathTime(5.0f)
		, mAttacked(false)
	{
	}

	RedPara::~RedPara()
	{
	}

	void RedPara::Initialize()
	{
	}

	void RedPara::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (mAttacked)
		{
			pos.y += 400.0f * Time::DeltaTime();
			tr->SetPosition(pos);

			mDeathTime -= Time::DeltaTime();
			if (mDeathTime < 0.0f)
			{
				Destroy(this);
			}
		}
		else
		{
			pos.x -= 30.0f * Time::DeltaTime();
			tr->SetPosition(pos);
		}
	}

	void RedPara::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void RedPara::OnCollisionEnter(Collider* other)
	{
		RedShell* redShell = dynamic_cast<RedShell*>(other->GetOwner());

		if (redShell)
		{
			Sound* sound = Resources::Load<Sound>(L"sfxNoDamage", L"..\\Assets\\Sound\\SFX\\WAV\\smw_stomp.wav");
			sound->Play(false);
		}
	}

	void RedPara::OnCollisionStay(Collider* other)
	{
		RedShell* redShell = dynamic_cast<RedShell*>(other->GetOwner());

		if (redShell)
		{
			this->GetComponent<Animator>()->PlayAnimation(L"Monster_Animation_RedKoopa_Dead", true);
			this->mAttacked = true;

			Transform* tr = GetComponent<Transform>();
			Collider* cl = GetComponent<Collider>();

			cl->SetActive(false);
		}
	}

	void RedPara::OnCollisionExit(Collider* other)
	{
	}
}
