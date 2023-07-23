#include "ntoRigidbody.h"
#include "CustomTime.h"
#include "GameObject.h"
#include "Transform.h"

namespace nto
{
	Rigidbody::Rigidbody()
		: Component(eComponentType::Rigidbody)
		, mMass(1.0f)
		, mFriction(100.0f)
		, GRAVITY(9.8f)
	{
	}

	Rigidbody::~Rigidbody()
	{
	}

	void Rigidbody::Initialize()
	{
	}

	void Rigidbody::Update()
	{
		//f(��) = m(����)a ���ӵ�
		mAccelation = mForce / mMass;

		// �ӵ��� ���ӵ��� ������� �� �ӵ��� ���´�
		mVelocity += mAccelation * Time::DeltaTime();

		if (!(mVelocity == Vector2::Zero))
		{

			// �ӵ��� �ݴ� �������� ������ ����
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			// ���������� ���� �ӵ� ���ҷ��� ���� �ӵ����� ū ���
			if (mVelocity.length() < friction.length())
			{
				// ����
				mVelocity = Vector2::Zero;
			}
			else
			{
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