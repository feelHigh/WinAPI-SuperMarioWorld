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
		// �̵�
		// F = M x A
		// A = F / M
		mAccelation = mForce / mMass;

		// �ӵ��� ���ӵ��� ���Ѵ�
		mVelocity += mAccelation * Time::DeltaTime();

		if (mbGround)
		{
			// ������ ������
			Vector2 gravity = mGravity;
			gravity.normalize();
			float dot = nto::math::Dot(mVelocity, gravity);
			mVelocity -= gravity * dot;
		}
		else
		{
			// ���߿� ���� ��
			mVelocity += mGravity * Time::DeltaTime();
		}

		// �ִ� �ӵ� ����
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

		// ������ ���� (����� ���� ����, �ӵ��� 0�� �ƴ� ���)
		if (!(mVelocity == Vector2::Zero))
		{
			// �ӵ��� �ݴ� �������� �������� ����
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� �� ū ���
			if (mVelocity.length() < friction.length())
			{
				// �ӵ��� 0���� �����
				mVelocity = Vector2(0.f, 0.f);
			}
			else
			{
				// �ӵ����� ���������� ���� �ݴ�������� �ӵ��� �����Ѵ�
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