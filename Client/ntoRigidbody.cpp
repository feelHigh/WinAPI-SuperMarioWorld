#include "ntoRigidbody.h"
#include "CustomTime.h"
#include "GameObject.h"
#include "Transform.h"

namespace nto
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(200.0f)
		, mbGround(false)
	{
		mLimitedVelocty.x = 200.0f;
		mLimitedVelocty.y = 1000.0f;
		mGravity = Vector2(0.0f, 2400.0f);
	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{
	}

	void Rigidbody::Update()
	{
		// 이동
		// F = M x A
		// A = F / M
		mAccelation = mForce / mMass;

		// 속도에 가속도를 더한다
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// 땅위에 있을때
			Vector2 gravity = mGravity;
			gravity.normalize();
			float dot = nto::math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			// 공중에 있을 때
			mVelocity += mGravity * Time::DeltaTime();
		}

		// 최대 속도 제한
		Vector2 gravity = mGravity;
		gravity.normalize();
		float dot = nto::math::Dot(mVelocity, gravity);
		gravity = gravity * dot;

		Vector2 sideVelocity = mVelocity - gravity;
		if (mLimitedVelocty.y < gravity.length())
		{
			gravity.normalize();
			gravity *= mLimitedVelocty.y;
		}

		if (mLimitedVelocty.x < gravity.length())
		{
			gravity.normalize();
			gravity *= mLimitedVelocty.x;
		}

		// 마찰력 조건 (적용된 힘이 없고, 속도가 0이 아닐 경우)
		if (!(mVelocity == Vector2::Zero))
		{
			// 속도에 반대 방향으로 마찰력을 적용
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 더 큰 경우
			if (mVelocity.length() < friction.length())
			{
				// 속도를 0으로 만든다
				mVelocity = Vector2(0.f, 0.f);
			}
			else
			{
				// 속도에서 마찰력으로 인한 반대방향으로 속도를 차감한다
				mVelocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);
		mForce.clear();
	}

	void Rigidbody::Render(HDC hdc)
	{

	}
}